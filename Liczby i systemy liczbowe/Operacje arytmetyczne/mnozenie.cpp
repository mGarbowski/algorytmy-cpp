#include <iostream>

using namespace std;


string sumaBinarnych(string a, string b)
{
    string wynik = "";
    int przeniesienie = 0;
    int suma;

    // Dodanie zer nieznaczących dla wyrownania dlugosci
    while (a.size() > b.size())
        b = "0" + b;

    while (b.size() > a.size())
        a = "0" + a;

    // Algorytm dodawania pod kreska
    for (int i = a.size()-1; i>= 0; i--)
    {
        // Przeliczenie kodow ASCII na wartosci liczbowe cyfr
        suma = a[i]-'0' + b[i]-'0' + przeniesienie;
        wynik = char(suma%2 + '0') + wynik;
        przeniesienie = suma / 2;
    }

    if (przeniesienie == 1)
        wynik = "1" + wynik;

    return wynik;
}


string iloczyn(string a, string b)
{
    string wynik = "";
    for (int i = b.size()-1; i >= 0; i--)
    {
        if (b[i] == '1')
            wynik = sumaBinarnych(wynik, a);
        
        a = a + '0';
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
    
    cout << "a*b = " << iloczyn(a, b);

    return 0;
}