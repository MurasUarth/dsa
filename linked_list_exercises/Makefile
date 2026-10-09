CC = gcc
CFLAGS = -Wall -Wextra 

programa: main.o lista.o
	$(CC) $(CFLAGS) -o programa main.o lista.o

main.o: main.c lista.h
	$(CC) $(CFLAGS) -c main.c

lista.o: lista.c lista.h
	$(CC) $(CFLAGS) -c lista.c

.PHONY: clean
clean:
	rm -f *.o programa