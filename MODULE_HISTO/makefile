CC=gcc
CFLAGS=-Wall -Wextra -ansi -pedantic
INC=./histogram.h ../MODULE_IMAGE/objet.h ../MODULE_IMAGE/classe.h ../MODULE_IMAGE/point.h ../MODULE_IMAGE/move_type.h ../MODULE_IMAGE/image.h ../MODULE_IMAGE/image.c

all: histoTest ppmhist quantitest

histoTest: histogram.o image.o histoTest.o
	$(CC) $^ -o $@ -g

quantitest: histogram.o image.o quantiTest.o quantification.o
	$(CC) $^ -o $@ -g

ppmhist: ppmhist.o histogram.o image.o
	$(CC) $^ -o $@ -g

histogram.o: histogram.c histogram.h
	$(CC) $(CFLAGS) $< -c

quantification.o: quantification.c quantification.h
	$(CC) $(CFLAGS) $< -c

quantiTest.o: quantiTest.c histogram.h quantification.h
	$(CC) $(CFLAGS) $< -c

ppmhist.o: ppmhist.c histogram.h
	$(CC) $(CFLAGS) $< -c

image.o: ../MODULE_IMAGE/image.c ../MODULE_IMAGE/image.h 
	$(CC) $(CFLAGS) $< -c
clear:
	rm -f *~
	rm -f *.o

.PHONY: all clear
