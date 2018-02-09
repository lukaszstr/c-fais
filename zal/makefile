CC = gcc
CFLAGS=-Wall -ansi -pedantic
#LIBS =
TEMPDIR   := tempdir

dummy: dummycrypter.o cipher.c decipher.c alokator.c deklaracje.h
	- mkdir tempdir
	- cd tempdir
	$(CC) $(CFLAGS) -o dummy dummycrypter.c deklaracje.h cipher.c decipher.c alokator.c
	- mv *.o ./tempdir
	- rm -rf tempdir
