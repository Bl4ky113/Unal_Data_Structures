
CC=/bin/gcc
SHELL=/bin/sh

TST_OUTPUT="libtest.out"
OBJ_OUTPUT="libtest.o"
LIB_OUTPUT="libtest.so"

ERROR_FLAGS=-Wall -Werror

objects: libtest.c test.h
	$(CC) -c -o $(OBJ_OUTPUT) $(ERROR_FLAGS) libtest.c -fpic

lib: objects
	$(CC) -shared -o $(LIB_OUTPUT) $(OBJ_OUTPUT)

clean:
	rm -f $(OBJ_OUTPUT) $(OBJ_LIB) $(TST_OUTPUT)
