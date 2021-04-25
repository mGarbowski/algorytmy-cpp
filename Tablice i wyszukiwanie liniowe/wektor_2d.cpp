#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;


int main()
{
    vector<vector<int> > macierz;
    int rozmiar;
    cout << "Rozmiar = ";
    cin >> rozmiar;

    macierz.resize(rozmiar);
    for (int i = 0; i < macierz.size(); i++)
    {
        macierz[i].resize(i+1);
    }

    // Wylosowanie
    srand(time(0));
    for (int i = 0; i < macierz.size(); i++)
    {
        for (int j = 0; j < macierz[i].size(); j++)
        {
            macierz[i][j] = rand() % 100;
        }
    }

    // Wypisanie
    for (int i = 0; i < macierz.size(); i++)
    {
        for (int j = 0; j < macierz[i].size(); j++)
        {
            cout << macierz[i][j] << " ";
        }
        cout << endl;
    }
}