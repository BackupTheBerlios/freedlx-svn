#!/usr/bin/make

CC = gcc
CFLAGS = -Wall -ansi -pedantic -ggdb

test: test.o core.o
	$(CC) test.o core.o -o test
	./test

test.o: test.c core.h
	$(CC) $(CFLAGS) -c test.c

core.o: core.c core.h
	$(CC) $(CFLAGS) -c core.c

clean:
	rm -rf *.o
