CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -std=c89
DEPS = structs.h errors.h lists.h
OBJ = main.o push_pall.o tokens.o get_func.c cleaner.c

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) 

monty: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

Phony: cln

cln:
	rm -f *.o *.out
