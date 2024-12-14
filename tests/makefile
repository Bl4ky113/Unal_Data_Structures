
CC=/bin/gcc
SHELL=/bin/sh

libtest:
	$(CC) -I../libtest -c -Wall -ltest libtest_test.c -o libtest_test.o
	$(CC) -L../libtest -ltest libtest_test.o -Wl,-R../libtest -Wall -Werror -o libtest_test.out 

stack:
	$(CC) -c -I../stack -lstack -Wall -o stack_test.o stack_test.c
	$(CC) -L../stack -lstack -Wl,-R../stack -Wall -Werror stack_test.o -o stack_test.out

test-stack:
	$(CC) -c -I../stack -lstack -Wall -o stack_test.o stack_test.c
	$(CC) -L../stack -lstack -Wl,-R../stack -Wall -Werror stack_test.o -o stack_test.out -g
