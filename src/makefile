CC = gcc
CFLAGS = -Wall -Werror -pedantic

all: prueba

prueba: main.c memoria.c cpu.c
	$(CC) $(CFLAGS) main.c memoria.c cpu.c -o prueba

clean:
	rm -f *.o prueba

#main.o: main.c
#	$(CC) $(CFLAGS) -c main.c

#cpu.o: cpu.c
#	$(CC) $(CFLAGS) -c cpu.c

#memoria.o: memoria.c 
#	$(CC) $(CFLAGS) -c memoria.c 
