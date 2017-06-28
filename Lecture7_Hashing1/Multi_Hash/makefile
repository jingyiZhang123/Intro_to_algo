
CC=c99
CFLAGS=-c -Wall

all: clean main
	./main

main: mhash.o main.o
	$(CC) -o main mhash.o main.o

main.o:
	$(CC) $(CFLAGS) main.c

mhash.o:
	$(CC) $(CFLAGS) mhash.c

clean:
	rm -rf *.o main
