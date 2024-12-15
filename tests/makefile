
CC=/bin/gcc
SHELL=/bin/sh

libtest:
	$(CC) -I../libtest -c -Wall -ltest libtest_test.c -o libtest_test.o
	$(CC) -L../libtest -ltest libtest_test.o -Wl,-R../libtest -Wall -Werror -o libtest_test.out 

stack:
	$(CC) -c -I../stack -lstack -Wall -o stack_test.o stack_test.c
	$(CC) -L../stack -lstack -Wl,-R../stack -Wall -Werror stack_test.o -o stack_test.out

test-stack:
	$(CC) -c -I../stack -lstack_test -Wall -o stack_test.o stack_test.c -g
	$(CC) -L../stack -lstack_test -Wl,-R../stack -Wall -Werror stack_test.o -o stack_test.out -g

queue:
	$(CC) -c -I../queue -lqueue -Wall -o queue_test.o queue_test.c
	$(CC) -L../queue -lqueue -Wl,-R../queue -Wall -Werror queue_test.o -o queue_test.out

test-queue:
	$(CC) -c -I../queue -lqueue_test -Wall -o queue_test.o queue_test.c -g
	$(CC) -L../queue -lqueue_test -Wl,-R../queue -Wall -Werror queue_test.o -o queue_test.out -g
