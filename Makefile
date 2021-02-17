CC=gcc

LFLAGS=-L. -lm
CFLAGS=-Wall -Werror -Wpedantic -O3 -fno-strict-aliasing

all:
	$(CC) $(CFLAGS) -shared -o libintarith.so -fPIC intarith.c $(LFLAGS)

tests:
	$(CC) $(CFLAGS) tests.c intarith.c -o tests $(LFLAGS)

clean:
	rm -rf *.so
	rm -rf tests

install:
	cp libintarith.so /usr/lib/libintarith.so

remove:
	rm -rf /usr/lib/libintarith.*
