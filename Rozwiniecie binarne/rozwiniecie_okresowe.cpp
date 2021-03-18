// Do poprawienia: zapis rozwinięcia nieokresowych ułamków

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Deklaracja zmiennych
    vector<int> calkowite;
    vector<int> liczniki;
    int licznik, mianownik, calkowita;
    bool jestOkres = false;
    int i;

    // Wczytanie
    cout << "Licznik = ";
    cin >> licznik;
    cout << "Mianownik = ";
    cin >> mianownik;

    // Szukanie okresu
    while (!jestOkres)
    {
        licznik *= 2;
        calkowita = licznik / mianownik;
        licznik = licznik % mianownik;

        i = 0;
        while (i < calkowite.size() && !jestOkres)
        {
            if (calkowite[i] == calkowita && liczniki[i] == licznik) {
                jestOkres = true;
            }
            else {
                i++;
            }
        }

        // Nie znaleziono okresu
        if (!jestOkres) {
            // dodanie elementu na koniec wektora
            calkowite.push_back(calkowita);
            liczniki.push_back(licznik);
        }
    }

    // Budowanie rozwinięcia
    string rozwiniecie = "0,";
    for (int j = 0; j < calkowite.size(); j++)
    {
        if (j == i){
            rozwiniecie += '(';
        }

        if (calkowite[j] == 0) {
            rozwiniecie += '0';
        }
        else {
            rozwiniecie += '1';
        }
    }

    if (jestOkres) {
        rozwiniecie += ')';
    }
    cout << rozwiniecie;

    return 0;
}