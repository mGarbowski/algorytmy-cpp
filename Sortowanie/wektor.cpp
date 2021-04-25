#include <iostream>
#include <vector>

// Funkcje losowe
#include <ctime>
#include <cstdlib>

// Wbudowana funkcja do sortowania
#include <algorithm>

using namespace std;


void Losuj(vector<int> &wektor)  // Przekazanie adresu w pamieci
{
    for (int i = 0; i < wektor.size(); i++)
    {
        wektor[i] = rand() % 100;
    }
}


void Wypisz(vector<int> wektor)
{
    for (int i = 0; i < wektor.size(); i++)
    {
        cout << wektor[i] << " ";
    }
    cout << endl;
}


void Sortuj(vector<int> &wektor)
{
    // Sortowanie przez wybieranie
    for (int i = 0; i < wektor.size()-1; i++)
    {
        int min = i;
        for (int j = i+1; j < wektor.size(); j++)
        {
            if (wektor[j] < wektor[min])
                min = j;

            swap(wektor[i], wektor[min]);
        }
    }
}

int main()
{
    srand(time(0));

    vector<int> wektor;
    int rozmiar;
    cout << "Rozmiar = ";
    cin >> rozmiar;
    wektor.resize(rozmiar);

    Losuj(wektor);
    Wypisz(wektor);

    //Sortuj(wektor);
    //Wypisz(wektor);

    // Sortowanie z wykorzystaniem wbudowanej funkcji C++
    // Przekzanie adresu w pamieci poczatku i konca wektora
    sort(wektor.begin(), wektor.end());
    Wypisz(wektor);

    return 0;
}