include ../system/include/MakeConfig

SUBDIRS_SYSTEM = IPC/src IPC/generate/src/system
SUBDIRS = IPC/script

ifeq ($(ENABLE_KCPU_COMMON), YES)
  SUBDIRS_SYSTEM += IPC/generate/src/secure
endif

all:
	echo "ycyang do all"
	set -e; for i in $(SUBDIRS); do $(MAKE) -C $$i; done

system-all:
	echo "ycyang do system-all"
	set -e; for i in $(SUBDIRS_SYSTEM); do $(MAKE) -C $$i; done

clean:
	set -e; for i in $(SUBDIRS_SYSTEM); do $(MAKE) clean -C $$i; done;
