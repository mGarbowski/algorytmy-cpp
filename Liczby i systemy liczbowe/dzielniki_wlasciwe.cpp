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
    while (dzielnik * dzielnik < liczba)
    {
        if (liczba % dzielnik == 0)
        {
            dzielniki.push_back(dzielnik);
            dzielniki.push_back(liczba / dzielnik);
        }

        dzielnik++;
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