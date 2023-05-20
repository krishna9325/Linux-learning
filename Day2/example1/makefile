#hellomake: hellomake.c hellofunc.c hellomake.h
#	gcc -o hellomake hellomake.c hellofunc.c -I .

# makefile for a C program

#CC = gcc


CC = gcc
CFLAGS = -Wall -Wextra -pedantic

all: hello

hello: hellomake.o hellofunc.o
	$(CC) -o hello hellomake.o hellofunc.o

hellomake.o: hellomake.c
	$(CC) $(CFLAGS) -c hellomake.c -I.

hellofunc.o: hellofunc.c
	$(CC) $(CFLAGS) -c hellofunc.c -I.

clean:
	rm -f hello hellomake.o hellofunc.o
