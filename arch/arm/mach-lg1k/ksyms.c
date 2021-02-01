#include <linux/module.h>
#include <linux/init.h>

/* Exporting a symbol from /init/main.c */
EXPORT_SYMBOL(saved_command_line);

