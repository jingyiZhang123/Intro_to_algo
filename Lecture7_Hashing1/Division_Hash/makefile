
CC=c99
CFLAGS=-c -Wall

all: clean main
	./main

main: dhash.o main.o
	$(CC) -o main dhash.o main.o

main.o:
	$(CC) $(CFLAGS) main.c

dhash.o:
	$(CC) $(CFLAGS) dhash.c

clean:
	rm -rf *.o main
