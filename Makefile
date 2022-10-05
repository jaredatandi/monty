CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -std=c89
DEPS = structs.h errors.h
OBJ = main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) 

monty: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

Phony: cln

cln:
	rm -f *.o *.out
