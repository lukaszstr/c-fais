CC = gcc
CFLAGS=-Wall -ansi -pedantic
#LIBS = 
TEMPDIR   := tempdir
all:	
	- mkdir tempdir
	$(MAKE) $(MFLAGS) dummy
	- mv *.o ./tempdir
	- rm -rf tempdir

dummy: dummyencryptor.o
	- cd tempdir
	$(CC) $(CFLAGS) -o dummy dummyencryptor.o $(LIBS)

