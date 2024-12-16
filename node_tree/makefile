
CC=/bin/gcc
SHELL=/bin/sh

TST_OUTPUT="tree.out"
OBJ_TST_OUTPUT="tree.o.out"
OBJ_OUTPUT="tree.o"
LIB_OUTPUT="libtree.so"
TST_OBJ_OUTPUT="tree_test.o"
TST_LIB_OUTPUT="libtree_test.so"

STACK_FILE_NAME=-lstack
STACK_TST_FILE_NAME=-lstack_test
STACK_OBJ_FLAGS=-I../stack
STACK_LIB_FLAGS=-L../stack
STACK_WL_FLAGS=-R../stack

ERROR_FLAGS=-Wall -Werror

test: tree.c tree.h
	$(CC) $(STACK_OBJ_FLAGS) $(STACK_TST_FILE_NAME) $(ERROR_FLAGS) \
		-o $(OBJ_TST_OUTPUT) tree.c -c -g
	$(CC) $(STACK_LIB_FLAGS) $(STACK_TST_FILE_NAME) -Wl,$(STACK_WL_FLAGS) $(ERROR_FLAGS) \
		-o $(TST_OUTPUT) $(OBJ_TST_OUTPUT) -g

clean:
	rm -f $(TST_OUTPUT) $(OBJ_TST_OUTPUT) $(OBJ_OUTPUT) $(LIB_OUTPUT) $(TST_OBJ_OUTPUT) $(TST_LIB_OUTPUT)

