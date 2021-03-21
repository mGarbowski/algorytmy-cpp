#include <iostream>
#include <string>

using namespace std;

string zmienPodstawe(int liczba, int podstawa)
{
    // Zwraca string będący reprezentacją liczby dla podanej podstawy
    // Maksymalna podstawa - 16

    if (podstawa > 16)
        return "Niepoprawna podstawa";

    string cyfry = "0123456789ABCDEF";
    string wynik = "";

    while (liczba > 0)
    {
        wynik = cyfry[liczba % podstawa] + wynik;
        liczba = liczba / podstawa;
    }

    return wynik;
}

int oblicz(string liczba, int podstawa)
{
    // Zwraca wartość liczby w danej podstawie (w systemie dziesietnym)
    // Maksymalna podstawa - 16

    if (podstawa > 16)
        return -1;

    int wynik = 0;
    int potega = 1;

    for (int i = liczba.size()-1; i >= 0; i--)
    {
        if (liczba[i] >= 'A' && liczba[i] <= 'F')
        {
            wynik += (liczba[i] - 'A' + 10) * potega;
        }
        if (liczba[i] >= '0' && liczba[i] <= '9')
        {
            wynik += (liczba[i] - '0') * potega;
        }

        potega = potega * podstawa;
    }

    return wynik;
}

int main()
{
    int liczba; 
    int podstawa;
    
    cout << "Liczba ";
    cin >> liczba;
    cout << "Podstawa ";
    cin >> podstawa;

    cout << zmienPodstawe(liczba, podstawa);
    
    return 0;
}