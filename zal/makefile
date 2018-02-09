CC = gcc
CFLAGS=-Wall -ansi -pedantic
#LIBS =
TEMPDIR   := tempdir

dummycrypter: dummycrypter.o cipher.c decipher.c alokator.c deklaracje.h
	- mkdir tempdir
	- cd tempdir
	$(CC) $(CFLAGS) -o dummycrypter dummycrypter.c deklaracje.h cipher.c decipher.c alokator.c
	- mv *.o ./tempdir
	- rm -rf tempdir
