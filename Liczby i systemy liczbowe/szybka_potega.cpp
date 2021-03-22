#include <iostream>

using namespace std;

int potega(int podstawa, int wykladnik)
{
    // Algorytm szybkiego podnoszenia do potęgi
    // Korzysta z faktu że każdy wykładnik można przedstawić
    // jako sumę potęg liczby 2

    long long wynik = 1;
    long long temp = podstawa;

    while (wykladnik > 0)
    {
        if (wykladnik % 2 == 1)
            wynik = wynik * temp;

        wykladnik = wykladnik / 2;

        if (wykladnik > 0)
            temp = temp * temp;
    }

    return wynik;
}


int main()
{
    int podstawa, wykladnik;

    cout << "x = ";
    cin >> podstawa;
    cout << "n = ";
    cin >> wykladnik;
    
    cout << "x^n = " << potega(podstawa, wykladnik);

    return 0;
}