#!/usr/bin/make

CC = gcc
GTK_LIBS= `pkg-config gtk+-2.0 --libs`
GTK_CFLAGS= `pkg-config gtk+-2.0 --cflags`
CFLAGS = -Wall -ansi -pedantic -ggdb
HEADERS= core.h gui.h
TEST_SOURCES=core.c test.c
TEST_OBJS=$(TEST_SOURCES:.c=.o)
GUI_SOURCES=core.c gui.c
GUI_OBJS=$(GUI_SOURCES:.c=.o)
	
default:	all
all:		test gui
test: $(TEST_OBJS)
	$(CC) $(TEST_OBJS) -o $@
gui: $(GUI_OBJS)
	$(CC) $(GTK_LIBS) $(GUI_OBJS) -o $@
.c.o:	$(HEADERS)
	$(CC) $(GTK_CFLAGS) $(CFLAGS) -c $< -o $@
#gui.o:	gui.c	core.h
#	$(CC) $(GTK_CFLAGS) $(CFLAGS) -c $< -o $@
#test.o: test.c core.h
#	$(CC) $(CFLAGS) -c $< -o $@
#core.o: core.c core.h
#	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -rf *.o test gui
