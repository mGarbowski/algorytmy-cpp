#include <iostream>

using namespace std;


bool CzyPierwsza(int liczba)
{

    bool czyPierwsza = (liczba > 1);

    // Wyklucza liczby podzielne przez 2 i 3
    if (liczba > 2 && liczba % 2 == 0)
        czyPierwsza = false;
    if (liczba > 3 && liczba % 3 == 0)
        czyPierwsza = false;


    // Sprawdzenie dzielnikow w postaci
    // 6i + 1 oraz 6i - 1
    // Z przedziału [5, sqrt(n)]
    int dizelnik = 5;
    while (czyPierwsza && dizelnik * dizelnik <= liczba)
    {
        if (liczba % dizelnik == 0)
            czyPierwsza = false;
        else if (liczba % (dizelnik + 2) == 0)
            czyPierwsza = false;
        else
            dizelnik += 6;
    }
    
    return czyPierwsza;
}


int main()
{
    int liczba;
    cout << "Liczba = ";
    cin >> liczba;

    if (CzyPierwsza(liczba))
        cout << "Liczba pierwsza";
    else
        cout << "Liczba zlozona";

    return 0;
}