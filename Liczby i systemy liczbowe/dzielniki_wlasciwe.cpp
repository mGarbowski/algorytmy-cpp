// Program znajduje dzielniki właściwe liczby i przechowuje je w vectorze
// a następnie wypisuje

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> dzielniki;
    int liczba, i;
    int dzielnik = 2;

    cout << "Liczba = ";
    cin >> liczba;

    // Szukanie dzielników
    for (dzielnik = 2; dzielnik*dzielnik < liczba; dzielnik++)
    {
        if (liczba % dzielnik == 0)
        {
            dzielniki.push_back(dzielnik);
            dzielniki.push_back(liczba / dzielnik);
        }
    }

    if (dzielnik * dzielnik == liczba)
    {
        dzielniki.push_back(dzielnik);
    }

    // Wypisanie
    sort(dzielniki.begin(), dzielniki.end());
    for (i = 0; i < dzielniki.size()-1; i++)
    {
        cout << dzielniki[i] <<", ";
    }
    cout << dzielniki[i];
    
    return 0;
}