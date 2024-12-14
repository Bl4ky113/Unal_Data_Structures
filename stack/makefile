
CC=/bin/gcc
SHELL=/bin/sh

TST_OUTPUT="teststack.out"
OBJ_OUTPUT="stack.o"
LIB_OUTPUT="libstack.so"

ERROR_FLAGS=-Wall -Werror

test: stack.c
	$(CC) -o $(TST_OUTPUT) $(ERROR_FLAGS) stack.c -g

objects: stack.c stack.h
	$(CC) -c -o $(OBJ_OUTPUT) $(ERROR_FLAGS) stack.c -fpic

lib: objects
	$(CC) -shared -o $(LIB_OUTPUT) $(OBJ_OUTPUT)

clean:
	rm -f $(OBJ_OUTPUT) $(OBJ_LIB) $(TST_OUTPUT)
