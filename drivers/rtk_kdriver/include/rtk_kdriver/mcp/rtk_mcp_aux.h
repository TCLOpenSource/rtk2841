#ifndef __MCP_AUX_H__
#define __MCP_AUX_H__

int mcp_is_pli_address(unsigned int addr);

unsigned long pli_to_kernel(unsigned int addr);

void mcp_dump_data(unsigned char* data, unsigned int len);

#endif //__MCP_AUX_H__ 
