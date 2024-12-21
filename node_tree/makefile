
CC=/bin/gcc
SHELL=/bin/sh

TST_OUTPUT="tree.out"
OBJ_TST_OUTPUT="tree.o.out"
OBJ_OUTPUT="tree.o"
LIB_OUTPUT="libnode_tree.so"
TST_OBJ_OUTPUT="node_tree_test.o"
TST_LIB_OUTPUT="libnode_tree_test.so"

ERROR_FLAGS=-Wall -Werror

test: tree.c tree.h
	$(CC) $(ERROR_FLAGS) \
		-o $(OBJ_TST_OUTPUT) tree.c -c -g
	$(CC) $(ERROR_FLAGS) \
		-o $(TST_OUTPUT) $(OBJ_TST_OUTPUT) -g

objects: tree.c tree.h
	$(CC) -c -o $(OBJ_OUTPUT) $(ERROR_FLAGS) tree.c -fpic

lib: objects
	$(CC) -shared -o $(LIB_OUTPUT) $(OBJ_OUTPUT)

test-objects: tree.c tree.h
	$(CC) -c -o $(TST_OBJ_OUTPUT) $(ERROR_FLAGS) tree.c -fpic -g

test-lib: test-objects
	$(CC) -shared -o $(TST_LIB_OUTPUT) $(TST_OBJ_OUTPUT) -g

clean:
	rm -f $(TST_OUTPUT) $(OBJ_TST_OUTPUT) $(OBJ_OUTPUT) $(LIB_OUTPUT) $(TST_OBJ_OUTPUT) $(TST_LIB_OUTPUT)

