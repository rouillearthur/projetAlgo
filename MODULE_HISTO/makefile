CC=gcc
CFLAGS=-Wall -Wextra -ansi -pedantic
HISTOT=histoTest

.PHONY: all clear
all: $(HISTOT)

$(HISTOT): histoTest.o histogram.o
	$(CC) $^ -o $@


%.o: %.c histogram.h
	$(CC) $(CFLAGS) $< -c




clear:
	rm -f *~
	rm -f *.o
