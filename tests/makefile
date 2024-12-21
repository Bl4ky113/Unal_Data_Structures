
CC=/bin/gcc
SHELL=/bin/sh

libtest: libtest_test.c
	$(CC) -I../libtest -c -Wall -ltest libtest_test.c -o libtest_test.o
	$(CC) -L../libtest -ltest libtest_test.o -Wl,-R../libtest -Wall -Werror -o libtest_test.out 

stack: stack_test.c
	$(CC) -c -I../stack -lstack -Wall -o stack_test.o stack_test.c
	$(CC) -L../stack -lstack -Wl,-R../stack -Wall -Werror stack_test.o -o stack_test.out

test-stack: stack_test.c
	$(CC) -c -I../stack -lstack_test -Wall -o stack_test.o stack_test.c -g
	$(CC) -L../stack -lstack_test -Wl,-R../stack -Wall -Werror stack_test.o -o stack_test.out -g

queue: queue_test.c
	$(CC) -c -I../queue -lqueue -Wall -o queue_test.o queue_test.c
	$(CC) -L../queue -lqueue -Wl,-R../queue -Wall -Werror queue_test.o -o queue_test.out

test-queue: queue_test.c
	$(CC) -c -I../queue -lqueue_test -Wall -o queue_test.o queue_test.c -g
	$(CC) -L../queue -lqueue_test -Wl,-R../queue -Wall -Werror queue_test.o -o queue_test.out -g

ntree: tree_test.c
	$(CC) -c -I../node_tree -lnode_tree -Wall -o tree_test.o tree_test.c 
	$(CC) -L../node_tree -lnode_tree -Wl,-R../node_tree -Wall -Werror tree_test.o -o tree_test.out

test-ntree: tree_test.c
	$(CC) -c -I../node_tree -lnode_tree_test -Wall -o tree_test.o tree_test.c -g
	$(CC) -L../node_tree -lnode_tree_test -Wl,-R../node_tree -Wall -Werror tree_test.o -o tree_test.out -g
