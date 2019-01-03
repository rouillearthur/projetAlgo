CC=gcc
CFLAGS=-Wall -Wextra -ansi -pedantic
HISTOT=histoTest

all: $(HISTOT)
.PHONY: all clear

$(HISTOT): histogram.o histoTest.o 
	$(CC) $^ -o $@

%.o: %.c histogram.h
	$(CC) $(CFLAGS) $< -c

clear:
	rm -f *~
	rm -f *.o
