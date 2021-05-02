CC=gcc

FLAGS = -g -Wall 

all: lab1
	echo "./lab1 -I imagen1.raw -Z imagen1Z.raw -S imagen1S.raw -M 512 -N 512 -r 2 -b"

lab1: lab1.o io.o funciones.o
	${CC} lab1.o io.o funciones.o -o lab1 ${FLAGS}

lab1.o: lab1.c struct.h io.h funciones.h
	${CC} lab1.c -c ${FLAGS}

io.o: io.c struct.h io.h funciones.h
	${CC} io.c -c ${FLAGS}

funciones.o: funciones.c struct.h io.h funciones.h
	${CC} funciones.c -c ${FLAGS}

clean:
	rm lab1 *.o -f