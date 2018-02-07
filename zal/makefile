CC = gcc
CFLAGS=-Wall -ansi -pedantic
#LIBS =
TEMPDIR   := tempdir
all:
	- mkdir tempdir
	$(MAKE) $(MFLAGS) dummy
	- mv *.o ./tempdir
	- rm -rf tempdir

dummy: dummycrypter.o cipher.c decipher.c deklaracje.h
	- cd tempdir
	$(CC) $(CFLAGS) -o dummy dummycrypter.o deklaracje.h cipher.c decipher.c
