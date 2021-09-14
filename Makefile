CC=gcc
CFLAGS=-g
LIB=libalgolib.a

OBJ=graph.o

INC=graph.h

lib: $(OBJ)
	ar -rc $(LIB) $(OBJ)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

test:
	gcc -g main.c $(INC) $(LIB) -o test

clean:
	rm -rf *.o *.a test
