# c-fais

## cw1
januszk@th.if.uj.edu.pl

Nice. Logowanie po ssh zachodzi do ubuntu 18.04 Czy bedzie zmiana??

Repository with my works for laboratories.

unikać nadmiaru w plikach nagłówkowych

# 21.12.2017
Plik danych imię nazwisko ocena. Pisane niechlujnie. Ocena to :
* albo liczba całkowita <2,5>
* albo liczba rzeczyiwsta <1,75;5,25>
* liczba całkowita ze znakiem (+4 3- itp)

Przetwarzamy te pliki w tym sensie, że z każdego z p[lików gromadzę informację o ocenach każdego studenta, ogarniam alfabetycznie liczbę studentów, na końcu jeszcze średnia grupy. 
Cały main jest wielką pętlą po argumentach. 

main
	{pętla po arhumentach
		wczytuje pliki po linii
		}


FILE = fopen( argv[i], "r");
// while (!feof(FILE)) {
feof wypisuje 1 jak napotka koniec pliku. Feof sprawdza co będzie potem //

	{
	cuś?
	} until (feof(FILE));

qsort(grupa, 
// argumenty qsort macierz gromadząca studentów, liczba argumentów do posortowania, 

Napis to macierz znakowa. Czyli jakieś miejsca w pamięci, gdzie jest cokolwiek. Mój napis ma 3 znaki - kot. Czyli ma przypisane 4 wartości, ostatni jest końcem stringu. To jest 0. 
funkcja strlend? co potrafi wyczytać ile znaków jest przed końcem stringu. 















# 14.12.2017
## Lab 10
Imię Nazwisko Ocena
Nazwisko Imię: lista ocen (//tak jak były wpisane) i średnia z dwiema cyframi po przecinku
5,25 >= ocena >= 2
Jeśli ocena się nie podoba to raportujemy na stdout strumień numer 2. Podobnie z tym jak ocen jest inna ilość etc. 
Nie narażamy się na próby korek błędów. 

Struktura Danych. Grupa to prosta macierz, wektor defacto. 
//Imię i nazwisko to stringi, oceny w sumie też, bo nie opłaca się na konwertować bo stracimy informację jak to wygląda. / Czyli student to ciąg znaków imienia, string nazwiska, macierz jednowektorowa? jego ocen, oraz liczba //
Struktura. 

Na koniec średnia grupy. 

Algorytm na otwarcie pliku:
Program ma wczytywać plik(i) , a jak nie da rady to przerzucić na std error. 
Wczytuje dane i pr

Macierz ma 30 linii (studentów?)

int x[5] -- wskaźnik do macierzy?
Do przepisania 1 ciągu znaków na inny ciąg znaków służy specjalna funkcja.
strcp / czy strcpy?


# 07.11.2017
Lab 08
Wskaźniki też są dla ludzi. 

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

