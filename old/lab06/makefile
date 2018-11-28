CC = gcc
CFLAGS=-Wall -ansi
LIBS = -lm
TEMPDIR   := tempdir
all:	
	- mkdir tempdir
	$(MAKE) $(MFLAGS) mzero
	- mv *.o ./tempdir
#	- rm -rf tempdir

mzero: main.o func.o mzero.o func.h
	- cd tempdir
	$(CC) $(CFLAGS) -o mzero main.o mzero.o func.o $(LIBS)

