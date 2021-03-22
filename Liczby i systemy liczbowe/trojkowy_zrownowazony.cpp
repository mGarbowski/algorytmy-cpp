#include <iostream>

using namespace std;


int trojkowyNaDziesietny(string liczba)
{
    int wynik = 0;
    int potega = 1;

    for (int i = liczba.size()-1; i >= 0; i--)
    {
        switch (liczba[i])
        {
            case '-':
                wynik -= potega;
                break;
            case '0':
                break;
            case '+':
                wynik += potega;
                break;
        }

        potega = potega * 3;
    }

    return wynik;
}


int main()
{
    string liczba;
    cout << "Liczba w zrownowazonym systemie trojkowym:" << endl;
    cin >> liczba;
    cout << "Wartosc: " << trojkowyNaDziesietny(liczba);

    return 0;
}