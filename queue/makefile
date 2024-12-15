
CC=/bin/gcc
SHELL=/bin/sh

TST_OUTPUT="testqueue.out"
OBJ_OUTPUT="stack.o"
TST_OBJ_OUTPUT="stack_test.o"
LIB_OUTPUT="libqueue.so"
TST_LIB_OUTPUT="libqueue_test.so"

ERROR_FLAGS=-Wall -Werror

test: queue.c queue.h
	$(CC) -o $(TST_OUTPUT) $(ERROR_FLAGS) queue.c -g

objects: queue.c queue.h
	$(CC) -c -o $(OBJ_OUTPUT) $(ERROR_FLAGS) queue.c -fpic

test-objects: queue.c queue.h
	$(CC) -c -o $(TST_OBJ_OUTPUT) $(ERROR_FLAGS) queue.c -fpic -g

lib: objects
	$(CC) -shared -o $(LIB_OUTPUT) $(OBJ_OUTPUT)

test-lib: test-objects
	$(CC) -shared -o $(TST_LIB_OUTPUT) $(TST_OBJ_OUTPUT) -g

clean:
	rm -f $(OBJ_OUTPUT) $(LIB_OUTPUT) $(TST_OUTPUT) $(TST_LIB_OUTPUT) $(TST_OBJ_OUTPUT)
