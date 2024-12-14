
CC=/bin/gcc
SHELL=/bin/sh

libtest:
	$(CC) -I../libtest -c -Wall -ltest libtest_test.c -o libtest_test.o
	$(CC) -L../libtest -ltest libtest_test.o -Wl,-R../libtest -Wall -Werror -o libtest_test.out 

stack:
	$(CC) -L../stack/ -lstack -o stack.out -Wall stack_test.c
