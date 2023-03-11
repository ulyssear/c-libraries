CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c17 -g

all: clear test_strings test_bytestrings test_files test_uuencode
	./test_strings
	./test_bytestrings
	./test_files
	./test_uuencode

clear:
	-rm test_strings
	-rm test_bytestrings
	-rm test_files
	-rm test_uuencode

test_strings:
	$(CC) $(CFLAGS) -o test_strings strings.test.c

test_bytestrings:
	$(CC) $(CFLAGS) -o test_bytestrings bytestrings.test.c

test_files:
	$(CC) $(CFLAGS) -o test_files files.test.c

test_uuencode:
	$(CC) $(CFLAGS) -o test_uuencode uuencode.test.c


