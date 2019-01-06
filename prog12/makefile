# Makefile
CC = gcc

all: AwesomeDataBase.o funkcje_bazy.o
	$(CC) AwesomeDataBase.o funkcje_bazy.o -o AwesomeDataBase

AwesomeDataBase.o: AwesomeDataBase.c funkcje_bazy.c deklaracje.h
	$(CC) AwesomeDataBase.c -c -o AwesomeDataBase.o

funkcje_bazy.o: funkcje_bazy.c deklaracje.h
	$(CC) funkcje_bazy.c -c -o funkcje_bazy.o  

clean:
	echo Usuwam gotowe pliki
	rm -f *.o test