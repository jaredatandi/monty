CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -std=c89
DEPS = lists.h structs.h errors.h
OBJ = main.o handlers_1.o tokens.o get_func.o cleaner.o \
      ops.o handlers_2.o ops_2.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

monty: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

Phony: cln


cln:
	rm -f *.o *.out
