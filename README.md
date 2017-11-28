# c-fais
Repository with my works for laboratories.

unikać nadmiaru w plikach nagłówkowych

# 23.11.2017

bitowe.h
program głownu pobiera znak, wypisuje wszystkie jego bity używając biblioteki

Funkcje:
	w n-tym miejscu ustawić 0
	--||-- 1
	bierze w ntym i zmienia na przeciwny

W domu:
	Wsyztskie te funkcje korzystają z maski, oraz są (1?) linijkowe.
-- kilka różnych znaków, duże, małe, cyfry, zn. specjalne, (zgodność z ASCI)
-- kilka liczb całkowitych: duże, małe, dodatnie, ujemne.
-- kilka liczb rzeczywsitych

Objekt UNIA
	

Zmienić kierunki maski. najpierw maska=(1<<n);
				return >>n

# Ostatnio
0 - metoda bisekcji
1 - metoda siecznych

GDB - debugger


**To find out:**
* Czym się różni wskaźnik od adresu?
* Operacje binarne na przyszłe zajęcia. 



## MAKE
Program do tego, żeby nie rekoimpilować tego czego nie musmu kompilować.
Umożliwa zrobinie minimim teog co potzebne ( jak zmienisz tylko 1 pliczek, to nie musisz całego projektu kompiowac od nowa)

Taki plik zależy od takich innych plików. Poznajmey po tym że wynik jest starszy niż któryś z pliczków. 

Dla projektu main.c mzero.c func.c gcc tworzy *.o każdego w tmp potem je linkuje. 

Porządny makefile powinien zawierać deklaracje zmiennych

CFLAGS = -Wall -ansi -O
Musi być przynajmniej jeden tabulator.

### Makefile
// definicje zmiennych
// piszemy je dużymi literami
potem zależności
mzero: main.o func.o mzero.o
(mzero zależy od 3 takich plików )
[ make to wie
	*.o: *.c
	$(CC) $(CFLAGS) -c *.c
]

# w językach skryptowych tak się zaczyna komentarz
W makefile może być masa projektów i wtedy wywołujemy make _nazwa

Teraz cmake przejmuje.

# include "adfnda" w takich apostrofach szuka tam gdzie projekt.

