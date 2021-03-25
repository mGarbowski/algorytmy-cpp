#include <iostream>
#include <cmath>

using namespace std;

int NWD2(int a, int b)
{
    while (a*b != 0)
    {
        if (a > b)
            a = a % b;
        else 
            b = b % a;
    }

    return a + b;
}


int NWD(int a, int b)
{
    int temp;
    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}


struct wymierna 
{
    int licznik;
    int mianownik;
};

void skroc(wymierna &x)
{
    int nwd = NWD(x.licznik, x.mianownik);
    x.licznik = x.licznik / nwd;
    x.mianownik = x.mianownik / nwd;
}


string tekst(wymierna u)
{
    string tekst;
    if (u.licznik < 0)
        tekst += "(";
    tekst += char(u.licznik + '0');
    if (u.mianownik > 1)
        tekst += "/";
        tekst += char(u.mianownik+'0');
    if (u.licznik < 0)
        tekst += ")";

    return tekst;
}


int main()
{
    int a,b,c,d;
    cout << "Licznik = ";
    cin >> a;
    cout << "Mianownik = ";
    cin >> b;
    cout << "Licznik2 = ";
    cin >> c;
    cout << "Mianownik2 = ";
    cin >> d;

    wymierna ulamek1;
    ulamek1.licznik = a;
    ulamek1.mianownik = b;
    skroc(ulamek1);

    wymierna ulamek2;
    ulamek2.licznik = c;
    ulamek2.mianownik = d;
    skroc(ulamek2);

    cout << tekst(ulamek1) << " + " << tekst(ulamek2);
    cout << " = " << tekst(dodaj(ulamek1, ulamek2));

    return 0;
}