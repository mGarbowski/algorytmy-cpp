#include <iostream>

using namespace std;

string PrzeciwnaU2(string liczba)
{
    int i;
    // zamiana cyfr na przeciwne
    for (i=0; i<8; i++)
    {
        if (liczba[i]=='0')
            liczba[i] = '1';
        else
            liczba[i] = '0';
    }

    // Dodanie 1
    liczba = '0' + liczba;  // Wartownik
    i = 8;
    while (liczba[i] == '1')
    {
        liczba[i] = '0';
        i--;
    }
    liczba[i] = '1';

    return liczba.substr(1, 8);  // Zwrocenie wartosci bez wartownika
}


string roznica(string a, string b)
{
    // a-b
    // Liczby binarne zapisane na 8 bitach
    b = PrzeciwnaU2(b);

    
    string wynik = "";
    int przeniesienie = 0;
    int suma;

    // Algorytm dodawania pod kreska
    for (int i = a.size()-1; i>= 0; i--)
    {
        // Przeliczenie kodow ASCII na wartosci liczbowe cyfr
        suma = a[i]-'0' + b[i]-'0' + przeniesienie;
        wynik = char(suma%2 + '0') + wynik;
        przeniesienie = suma / 2;
    }

    return wynik;
}


int main()
{
    string a, b;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;

    cout << roznica(a, b);
    
    return 0;
}