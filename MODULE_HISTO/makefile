CC=gcc
CFLAGS=-Wall -Wextra -ansi -pedantic
HISTOT=histoTest
INC=./histogram.h ../MODULE_IMAGE/objet.h ../MODULE_IMAGE/classe.h ../MODULE_IMAGE/point.h ../MODULE_IMAGE/move_type.h ../MODULE_IMAGE/image.h

all: $(HISTOT)
.PHONY: all clear

$(HISTOT): histogram.o histoTest.o $(INC) 
	$(CC) $^ -o $@ -L../MODULE_IMAGE/ -limage64

%.o: %.c histogram.h
	$(CC) $(CFLAGS) $< -c

clear:
	rm -f *~
	rm -f *.o
