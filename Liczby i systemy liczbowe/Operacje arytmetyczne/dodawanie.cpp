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


string suma(string a, string b, int podstawa)
{
    if (podstawa < 2 || podstawa > 36)
        return "-1";

    int przen = 0, cyfraA, cyfraB, suma;
    string wynik = "";

    while (a.size() > b.size())
        b = "0" + b;
    while (b.size() > a.size())
        a = "0" + a;

    for (int i = a.size()-1; i >= 0; i--)
    {
        // Wczytanie wartosci liczbowej cyfr
        if (a[i] <= '9')
            cyfraA = a[i] - '0';
        else
            cyfraA = a[i] - 'A' + 10;

        if (b[i] <= '9')
            cyfraB = b[i] - '0';
        else
            cyfraB = b[i] - 'A' + 10;

        // Algorytm dodawania pod kreska
        suma = cyfraA + cyfraB + przen;
        przen = suma / podstawa;

        suma = suma % podstawa;
        if (suma <= 9)
            wynik = char(suma +'0') + wynik;
        else
            wynik = char(suma + 'A' - 10) + wynik;
    }

    if (przen != 0)
    {
        if (przen <= 9)
            wynik = char(przen + '0') + wynik;
        else
            wynik = char(przen +'A'-10) + wynik;
    }

    return wynik;
}

int main()
{
    string a, b;
    int podstawa;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "Podstawa = ";
    cin >> podstawa;

    cout << "Suma = " << suma(a,b, podstawa);

    return 0;
}