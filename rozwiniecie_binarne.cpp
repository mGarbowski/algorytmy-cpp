#include <iostream>

using namespace std;

string rozwiniecieBinarne(int licznik, int mianownik)
{
    // licznik < mianownik
    // NWD(licznik, mianownik) == 1
    // mianownik == 2^n

    string rozwiniecie = "0,";

    while (licznik > 0)
    {
        licznik *= 2;

        if (licznik / mianownik == 1)
        {
            rozwiniecie += "1";
        }
        else
        {
            rozwiniecie += "0";
        }

        licznik = licznik % mianownik;
    }

    return rozwiniecie;
}

int main()
{
    int licznik, mianownik;
    cout << "licznik < mianownik \nNWD(licznik, mianownik) == 1 \nmianownik == 2^n \n\n";
    cout << "Licznik = ";
    cin >> licznik;
    cout << "Mianownik = ";
    cin >> mianownik;

    cout << endl << licznik << "/" << mianownik << " = ";
    cout << rozwiniecieBinarne(licznik, mianownik);

    return 0;
}