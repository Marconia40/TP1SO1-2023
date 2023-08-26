CC = gcc
CFLAGS = -Wall -Werror -pedantic

all: prueba

prueba: memoria.o cpu.o
	$(CC) $(CFLAGS) memoria.o cpu.o -o prueba

cpu.o: cpu.c
	$(CC) $(CFLAGS) -c cpu.c

memoria.o: memoria.c 
	$(CC) $(CFLAGS) -c memoria.c 


clean:
	rm -f *.o prueba