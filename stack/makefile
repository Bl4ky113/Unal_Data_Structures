
CC=/bin/gcc
SHELL=/bin/sh

TST_OUTPUT="teststack.out"
OBJ_OUTPUT="stack.o"
LIB_OUTPUT="libstack.so"
TST_OBJ_OUTPUT="stack_test.o"
TST_LIB_OUTPUT="libstack_test.so"

ERROR_FLAGS=-Wall -Werror

test: stack.c
	$(CC) -o $(TST_OUTPUT) $(ERROR_FLAGS) stack.c -g

objects: stack.c stack.h
	$(CC) -c -o $(OBJ_OUTPUT) $(ERROR_FLAGS) stack.c -fpic

lib: objects
	$(CC) -shared -o $(LIB_OUTPUT) $(OBJ_OUTPUT)

test-objects: stack.c stack.h
	$(CC) -c -o $(TST_OBJ_OUTPUT) $(ERROR_FLAGS) stack.c -fpic -g

test-lib: test-objects
	$(CC) -shared -o $(TST_LIB_OUTPUT) $(TST_OBJ_OUTPUT) -g

clean:
	rm -f $(OBJ_OUTPUT) $(LIB_OUTPUT) $(TST_OUTPUT) $(TST_LIB_OUTPUT) $(TST_OBJ_OUTPUT)
