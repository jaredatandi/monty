CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -std=c89
DEPS = lists.h structs.h errors.h
OBJ = main.o push_pall.o tokens.o get_func.o cleaner.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) 

monty: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

Phony: cln

cln:
	rm -f *.o *.out
