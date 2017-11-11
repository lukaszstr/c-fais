## Komentarz
Rekurencyjny 
Podwaja swój stos.
(sys będzie zajmować się tylko sobą i tym żeby kolejny na stos)
----------------------------------------------------------------
## Na tych i przyszłych zajęciach zajmiemy się jednym programem, składającym się z kilku plików. 

Funkcja jednej zmiennej rzeczywiste
Szukamy miejsc zerowych.
// Równanie stanie się przestępne: 1- (x*e^(2x+3))

**Nasz projekt:**
* Program główny (ćwiczy i/o, pobiera dane)(przedział w którym szukam - do pobrania)
* funkcja (metoda bisekcji - sprawdzam w połowie przedziału)
* szukacz miejsca zerowego ( 2 warianty - aktywowane 
**Gdzie program główny przekazuje dane do szukacza który dla tych danych szuka miejsc zerowych funkjcji zakodowanej w funkcji) ma jeszcze podać liczbę kroków**
**funkcja zwraca liczbę kroków, ale którędy położenie miejsca zerowego?**
// Jak dla danej pary x1=/=x2 f(x) ma przeciwny znak to jest przynajmniej 1 miejsce zerowe (zakładając że są t funkcje ciągłe)
// Ciągłość muszę zagwarantować w funkcji
// minwind - najlepsza biblioteka z CERNU dla funkcji wielu zmiennych (w fortranie)
// podwójna precyzja ziarnistość, 100/2^(n) = 10^(-15) -> n = ln_2 10^17 = 17ln_2 10 = 50
// metoda siecznych:
// metoda stycznych - to wariant metody siecznych

* kryterium zbieżności -- kryterium przerwania dalszych obliczeń
- |f(x)| < E // funkcja ma moduł mniejszy od epsiliona >
- |x1-xp| < E // bardzo złe kryterium bo jak nie pracujemy w pobliżu 0>
- |(x1-xp)/xn| < Ex // lepsze >
* jak je połączyć? 
- I
- Albo // raczej ten


* maina napisać samemu
* interaktywnie pobieramy lewą, prawą granicę i epsilion, ma być ten sam w ramach umowy naszej
* nie podejmować się interkatywnego wprowadzania funkcji
* Ma natomiast pobrać interaktywnie 0/1 żeby wybrać funkcję
* 

## gcc -Wall -ansi -O -o project.o main.c funkcja.c szukacz.c -lm

// CO TO KURWA ZIARNO?


Za tydzień będzie make

Funkcja m0 (szukacz) jest typu double

Jak ma miejsce zerowe

(xl, fl) fl=axl+b --> b=fl-axl
(xp, fp) fp=axp+b --> fp =axp+fl-axl --> fp-fl=a(xp-xl)
--> a=(fp-fl)/(xp-xl)

x0=-(fl(x))


