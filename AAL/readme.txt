Jakub Jałowiec, WEiTI PW, 2018
------------------------------

Treść polecenia
Na półce są ułożone w przypadkowej kolejności pojemniki z atramentami w czterech kolorach: C, M, Y i K. Należy je uporządkować za pomocą robota w taki sposób, aby od lewej do prawej strony półki znalazły się kolejno: C, następnie M, następnie Y, a na końcu - K. Robot w jednym ruchu może pobrać jednocześnie dokładnie cztery sąsiednie pojemniki z dowolnego miejsca na półce i przenieść je na prawa stronę, za wszystkie pojemniki, a następnie dosunąć część pojemników w lewo, wypełniając lukę. Ułożyć plan pracy robota, dyktując w kolejnych ruchach, którą czwórkę pojemników przenieść na prawą stronę. Wykonać jak najmniejszą liczbę ruchów. Porównać czas obliczeń i wyniki różnych metod.

Tryby uruchamiania:
"./ AAL -stdin": uruchmia program w trybie wczytywania sekwencji liter {C, M, Y, K} z wejścia standardowego (konsoli).
"./ AAL -benchmark [-k _liczba] [-n _liczba] [-r _liczba] [-step _liczba]" - uruchamia program w trybie testowania automatycznego, na koniec wyświetla tabelkę z podsumowaniem czasów wykonania, '_liczba' to dowolna liczba całkowita dodatnia.

Konwencje:
1. danych wejściowych: sekwencje testowe wprowadzane przez użytkownika muszą być w formacie {C|M|Y|K}*, w innym wypadku program ma działanie nieprzewidziane.
2. prezentacji  wyników: w trybie "-stdin" program wyświetla dla każdego algorytmu czas jego wykonania, liczbę wykonanych elementarnych ruchów, polegających na przeniesieniu czterech pojemników na koniec ich listy i przesunięciu wszsytkich pojemników w lewo, tak aby zapełnić dziurę oraz wynik sortowania, tj. posortowaną półkę.
W trybie "-benchmark" program wyświetla tylko tabelę z podsumowaniem wyników działania algorytmu.

Moduły:
1. Algorithm.cpp + Algorithm.h: rozwiązanie problemu postawionego w treści zadania.
2. Benchmark.cpp + Benchmark.h: funkcje odpowiedzialne za automatyczne testowanie rozwiązania Algorithm
3. Interface.cpp + Interface.h: znakowy interfejs użytownika, przyjmuje wejście od użykownika i wywołuje odpowiednie metody.