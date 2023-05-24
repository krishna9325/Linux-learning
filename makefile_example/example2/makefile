#calcmake: calculator.c add.c mul.c div.c sub.c add.h div.h mul.h sub.h
#	gcc -O calcmake calculator.c add.c mul.c div.c sub.c -I.
	
CC = gcc
CFLAGS = -Wall -Wextra

all: calc

calc: *.o
	$(CC) -o calc *.o

*.o: 
	$(CC) $(CFLAGS) -c *.c -I.
	

clean:
	rm -f *.o calc
