#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/module.h>
#include <linux/miscdevice.h>
#include <rtk_kdriver/rtk_mcp.h>
#include "mcp/rtk_mcp_dgst.h"
#include "mcp/rtk_mcp_buff.h"
#include "mcp/rtk_mcp_aux.h"
#include "mcp/rtk_mcp_dbg.h"

#define MCP_DEV_FILE_NAME      "mcp_dgst"

/* IOCTL Command Definition */
#define MCP_DGST_IOC_MAGIC  'd'
#define MCP_DGST_IOCTL_INIT           	_IOW(MCP_DGST_IOC_MAGIC, 0,unsigned int)
#define MCP_DGST_IOCTL_UPDATE         	_IOW(MCP_DGST_IOC_MAGIC, 1, unsigned int)
#define MCP_DGST_IOCTL_FINAL          	_IOWR(MCP_DGST_IOC_MAGIC, 2, unsigned int)
#define MCP_DGST_IOCTL_PEEK           	_IOWR(MCP_DGST_IOC_MAGIC, 3, unsigned int)


/***************************************************************************
     ------------------- Device File Operations  --------------------
****************************************************************************/

/*------------------------------------------------------------------
 * Func : mcp_dgst_dev_open
 *
 * Desc : open function of md dev
 *
 * Parm : inode : inode of dev
 *        file  : context of file
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static
int mcp_dgst_dev_open(
	struct inode *inode,
	struct file *file
	)
{
    file->private_data = kmalloc(sizeof(MCP_MD_CTX),GFP_KERNEL);

    if (file->private_data==NULL)
        return -EFAULT;

    MCP_MD_CTX_init((MCP_MD_CTX*) file->private_data);

    ((MCP_MD_CTX*) file->private_data)->private_data = NULL;

    return 0;
}



/*------------------------------------------------------------------
 * Func : mcp_dgst_dev_release
 *
 * Desc : release function of mcp dev
 *
 * Parm : inode : inode of dev
 *        file  : context of file
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static
int mcp_dgst_dev_release(
    struct inode*      	inode,
    struct file*         	file
    )
{
    MCP_MD_CTX* ctx = (MCP_MD_CTX*) file->private_data;

    if (ctx)
    {
        if (ctx->private_data)
            free_mcpb((MCP_BUFF*)ctx->private_data);

        MCP_MD_CTX_cleanup(ctx);
        kfree(ctx);
    }

	return 0;
}



/*------------------------------------------------------------------
 * Func : mcp_dgst_dev_ioctl
 *
 * Desc : ioctl function of md dev
 *
 * Parm : inode : inode of dev
 *        file  : context of file
 *        cmd   : control command
 *        arg   : arguments
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static
long mcp_dgst_dev_ioctl(
    struct file*        	file,
    unsigned int         	cmd,
    unsigned long        	arg
    )
{
    MCP_MD_CTX* ctx = (MCP_MD_CTX*) file->private_data;
    MCP_BUFF mcpb;
    MCP_BUFF* kmcpb;
    unsigned char hash[MCP_MAX_DIGEST_SIZE];
    unsigned int hash_len;
    int ret = -EFAULT;

	switch (cmd)
    {
    	case MCP_DGST_IOCTL_INIT:
     	{
        	switch(arg)
			{
        		case MCP_MD_AES_H:
					return MCP_DigestInit(ctx, MCP_aes_h());
        		case MCP_MD_MARS_AES_H:
					return MCP_DigestInit(ctx, MCP_mars_aes_h());
        		case MCP_MD_SHA1:
					return MCP_DigestInit(ctx, MCP_sha1());
        		case MCP_MD_MARS_SHA1:
					return MCP_DigestInit(ctx, MCP_mars_sha1());
#ifdef CONFIG_RTK_KDRV_MCP_SHA256
        		case MCP_MD_SHA256:
					return MCP_DigestInit(ctx, MCP_sha256());
        		case MCP_MD_MARS_SHA256:
					return MCP_DigestInit(ctx, MCP_mars_sha256());
#endif
        	}
        	break;
    	}
    	case MCP_DGST_IOCTL_UPDATE:
 		{
        	if (copy_from_user((void __user *) &mcpb, (void __user *)arg, sizeof(MCP_BUFF)))
        	{
            	        mcp_warning("[MCP][DGST] WARNING, do dgst update failed, copy data from user failed\n");
				return -EFAULT;
        	}

        	// check is the MCP_buff is valid or not

        	if (mcp_is_pli_address(mcpb.head))
        	{
            	//mcpb.head = (unsigned char*)pli_to_kernel(mcpb.head);
            	//mcpb.data = (unsigned char*)pli_to_kernel(mcpb.data);
            	//mcpb.tail = (unsigned char*)pli_to_kernel(mcpb.tail);
            	//mcpb.end  = (unsigned char*)pli_to_kernel(mcpb.end);
				mcpb.head = pli_to_kernel(mcpb.head);
            	mcpb.data = pli_to_kernel(mcpb.data);
            	mcpb.tail = pli_to_kernel(mcpb.tail);
            	mcpb.end  = pli_to_kernel(mcpb.end);

            	ret = MCP_DigestUpdate(ctx, &mcpb);
        	}
        	else
        	{
            	kmcpb = (MCP_BUFF*) ctx->private_data;

            	if (kmcpb)
            	{
                	mcpb_purge(kmcpb);

                	if (mcpb_tailroom(kmcpb) < mcpb.len)
                	{
                    	if (kmcpb)
                        	free_mcpb(kmcpb);

                    	kmcpb = alloc_mcpb(mcpb.len);

                    	ctx->private_data = (void*) kmcpb;
                	}
            	}
            	else
            	{
                	kmcpb = alloc_mcpb(mcpb.len);
                 	ctx->private_data = (void*) kmcpb;
            	}

            	if (kmcpb==NULL)
            	{
                	mcp_warning("[MCP][DGST] WARNING, do dgst update failed, alloc mcpb buffer failed\n");
			    	return -EFAULT;
            	}

            	if (copy_from_user((void *) kmcpb->data, (void __user *)mcpb.data, mcpb.len)==0)
            	{
                	mcpb_put(kmcpb, mcpb.len);
                	ret = MCP_DigestUpdate(ctx, kmcpb);
            	}
        	}

			return ret;
    	}
    	case MCP_DGST_IOCTL_FINAL:
        {
        	if (MCP_DigestFinal(ctx, hash, &hash_len)<0)
            	return -EFAULT;

        	return (copy_to_user((unsigned char __user *)arg, hash, hash_len)<0) ? -EFAULT : hash_len;
    	}
    	case MCP_DGST_IOCTL_PEEK:
        {
        	if (MCP_DigestPeek(ctx, hash, &hash_len)<0)
            	return -EFAULT;

        	return (copy_to_user((unsigned char __user *)arg, hash, hash_len)<0) ? -EFAULT : hash_len;
    	}
		default:
	    	mcp_warning("[MCP][DGST] WARNING, unknown command - %08lx\n", cmd);
	    	mcp_warning("[MCP][DGST] MCP_DGST_IOCTL_INIT - %08lx\n", MCP_DGST_IOCTL_INIT);
	    	mcp_warning("[MCP][DGST] MCP_DGST_IOCTL_UPDATE - %08lx\n", MCP_DGST_IOCTL_UPDATE);
	    	mcp_warning("[MCP][DGST] MCP_DGST_IOCTL_FINAL - %08lx\n", MCP_DGST_IOCTL_FINAL);
	    	mcp_warning("[MCP][DGST] MCP_DGST_IOCTL_PEEK - %08lx\n", MCP_DGST_IOCTL_PEEK);
			return -EFAULT;
	}

    return ret;
}


#ifdef CONFIG_COMPAT
/*------------------------------------------------------------------
 * Func : mcp_dgst_dev_compat_ioctl
 *
 * Desc : ioctl function of md dev
 *
 * Parm : inode : inode of dev
 *        file  : context of file
 *        cmd   : control command
 *        arg   : arguments
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static
long mcp_dgst_dev_compat_ioctl(
    struct file*        	file,
    unsigned int         	cmd,
    unsigned long        	arg
    )
{
    MCP_MD_CTX* ctx = (MCP_MD_CTX*) file->private_data;
    compat_mcp_buff compat_mcpb;
    compat_mcp_buff* compat_kmcpb;
    MCP_BUFF mcpb;
    MCP_BUFF* kmcpb;
    unsigned char hash[MCP_MAX_DIGEST_SIZE];
    unsigned int hash_len;
    int ret = -EFAULT;

    switch (cmd)
    {
	    case MCP_DGST_IOCTL_INIT:
		    {
			    switch(arg)
			    {
				    case MCP_MD_AES_H:
					    return MCP_DigestInit(ctx, MCP_aes_h());
				    case MCP_MD_MARS_AES_H:
					    return MCP_DigestInit(ctx, MCP_mars_aes_h());
				    case MCP_MD_SHA1:
					    return MCP_DigestInit(ctx, MCP_sha1());
				    case MCP_MD_MARS_SHA1:
					    return MCP_DigestInit(ctx, MCP_mars_sha1());
#ifdef CONFIG_REALTEK_MCP_SHA256
				    case MCP_MD_SHA256:
					    return MCP_DigestInit(ctx, MCP_sha256());
				    case MCP_MD_MARS_SHA256:
					    return MCP_DigestInit(ctx, MCP_mars_sha256());
#endif
			    }
			    break;
		    }
	    case MCP_DGST_IOCTL_UPDATE:
		    {
			    if (copy_from_user((void __user *) &compat_mcpb, compat_ptr(arg), sizeof(compat_mcp_buff)))
			    {
				    mcp_warning("[MCP][DGST] WARNING, do dgst update failed, copy data from user failed\n");
				    return -EFAULT;
			    }

			    // check is the MCP_buff is valid or not

			    if (mcp_is_pli_address(compat_mcpb.head))
			    {
				    mcpb.head = pli_to_kernel(compat_mcpb.head);
				    mcpb.data = pli_to_kernel(compat_mcpb.data);
				    mcpb.tail = pli_to_kernel(compat_mcpb.tail);
				    mcpb.end  = pli_to_kernel(compat_mcpb.end);
				    mcpb.len = compat_mcpb.len;

				    ret = MCP_DigestUpdate(ctx, &mcpb);
			    }
			    else
			    {
				    compat_kmcpb = (compat_mcp_buff*) ctx->private_data;

				    if (compat_kmcpb)
				    {
					    kmcpb->head = compat_ptr(compat_kmcpb->head);
					    kmcpb->data = compat_ptr(compat_kmcpb->data);
					    kmcpb->tail = compat_ptr(compat_kmcpb->tail);
					    kmcpb->end = compat_ptr(compat_kmcpb->end);
					    kmcpb->len = compat_kmcpb->len;

					    mcpb_purge(kmcpb);

					    if (mcpb_tailroom(kmcpb) < compat_mcpb.len)
					    {
						    if (compat_kmcpb)
							    free_mcpb(kmcpb);

						    kmcpb = alloc_mcpb(compat_mcpb.len);

						    ctx->private_data = (void*) kmcpb;
					    }
				    }
				    else
				    {
					    kmcpb = alloc_mcpb(compat_mcpb.len);
					    ctx->private_data = (void*) kmcpb;
				    }

				    if (kmcpb==NULL)
				    {
					    mcp_warning("[MCP][DGST] WARNING, do dgst update failed, alloc mcpb buffer failed\n");
					    return -EFAULT;
				    }

				    if (copy_from_user((void *) kmcpb->data, compat_ptr(compat_mcpb.data), compat_mcpb.len)==0)
				    {
					    mcpb_put(kmcpb, compat_mcpb.len);
					    ret = MCP_DigestUpdate(ctx, kmcpb);
				    }
			    }

			    return ret;
		    }
	    case MCP_DGST_IOCTL_FINAL:
		    {
			    if (MCP_DigestFinal(ctx, hash, &hash_len)<0)
				    return -EFAULT;

			    return (copy_to_user(compat_ptr(arg), hash, hash_len)<0) ? -EFAULT : hash_len;
		    }
	    case MCP_DGST_IOCTL_PEEK:
		    {
			    if (MCP_DigestPeek(ctx, hash, &hash_len)<0)
				    return -EFAULT;

			    return (copy_to_user(compat_ptr(arg), hash, hash_len)<0) ? -EFAULT : hash_len;
		    }
	    default:
		    mcp_warning("[MCP][DGST] WARNING, unknown command - %08lx\n", cmd);
		    mcp_warning("[MCP][DGST] MCP_DGST_IOCTL_INIT - %08lx\n", MCP_DGST_IOCTL_INIT);
		    mcp_warning("[MCP][DGST] MCP_DGST_IOCTL_UPDATE - %08lx\n", MCP_DGST_IOCTL_UPDATE);
		    mcp_warning("[MCP][DGST] MCP_DGST_IOCTL_FINAL - %08lx\n", MCP_DGST_IOCTL_FINAL);
		    mcp_warning("[MCP][DGST] MCP_DGST_IOCTL_PEEK - %08lx\n", MCP_DGST_IOCTL_PEEK);
		    return -EFAULT;
    }

    return ret;
}
#endif

static struct file_operations mcp_dgst_dev_ops =
{
	.owner				= THIS_MODULE,
	.unlocked_ioctl	= mcp_dgst_dev_ioctl,
#ifdef CONFIG_COMPAT
	.compat_ioctl 			= mcp_dgst_dev_compat_ioctl,
#endif
	.open				= mcp_dgst_dev_open,
	.release			= mcp_dgst_dev_release,
};

static struct miscdevice rtk_mcp_dgst_miscdev = {
        MISC_DYNAMIC_MINOR,
        MCP_DEV_FILE_NAME,
        &mcp_dgst_dev_ops,
};


/***************************************************************************
     ------------------- module init / exit stubs ----------------
****************************************************************************/

static int __init mcp_dgst_dev_init(void)
{
        if (misc_register(&rtk_mcp_dgst_miscdev))
                return -ENODEV;
        return 0;
}


static void __exit mcp_dgst_dev_exit(void)
{
        misc_deregister(&rtk_mcp_dgst_miscdev);
}



module_init(mcp_dgst_dev_init);
module_exit(mcp_dgst_dev_exit);
