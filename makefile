CC=gcc

FLAGS = -g -Wall -lm

all: lab1

lab1: lab1.o 
	gcc lab1.o -o lab1 ${FLAGS}

lab1.o: lab1.c struct.h
	gcc lab1.c -c ${FLAGS}

clean:
	rm lab1 *.o -f