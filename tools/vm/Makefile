# Makefile for vm tools
#
TARGETS=page-types slabinfo page_owner_sort page_owner_parser

LIB_DIR = ../lib/api
LIBS = $(LIB_DIR)/libapi.a

CC = $(CROSS_COMPILE)gcc
CFLAGS = -Wall -Wextra -I../lib/
LDFLAGS = $(LIBS)

$(TARGETS): $(LIBS)

$(LIBS):
	make -C $(LIB_DIR)

%: %.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

clean:
	$(RM) page-types slabinfo page_owner_sort page_owner_parser
	make -C $(LIB_DIR) clean
