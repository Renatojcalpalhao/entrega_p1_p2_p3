CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: bfc bfe

bfc: bfc.c
	$(CC) $(CFLAGS) bfc.c -o bfc

bfe: bfe.c
	$(CC) $(CFLAGS) bfe.c -o bfe

clean:
	rm -f bfc bfe

.PHONY: all clean