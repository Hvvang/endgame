CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -Werror -Wpedantic -lncurses -lpthread
SRC=*.c

all:
	make install

install:
	
	$(CC) $(CFLAGS) *.c

example:

	$(CC) $(CFLAGS) example.c
