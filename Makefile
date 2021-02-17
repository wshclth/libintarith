CC=gcc

LFLAGS=-L. -lm
CFLAGS=-Wall -Werror -Wpedantic -O3 -fno-strict-aliasing

all:
	$(CC) $(LFLAGS) $(CFLAGS) -shared -o libintarith.so -fPIC intarith.c

tests:
	$(CC) $(LFLAGS) $(CFLAGS) tests.c intarith.c -o tests

clean:
	rm -rf *.so
	rm -rf tests

install:
	cp libintarith.so /usr/lib/libintarith.so

remove:
	rm -rf /usr/lib/libintarith.*
