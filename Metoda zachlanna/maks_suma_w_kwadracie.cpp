#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;


const int ROZMIAR = 5;


void wylosujTablice(int tablica[][ROZMIAR+1])
{
    for (int i = 0; i < ROZMIAR; i++)
        for (int j = 0; j < ROZMIAR; j++)
            tablica[i][j] = rand() % 9 + 1;

    // Dodanie wartownikow
    for (int i = 0; i < ROZMIAR; i++)
    {
        tablica[ROZMIAR][i] = 0;
        tablica[i][ROZMIAR] = 0;
    }
       
}


void wypiszTablice(int tablica[][ROZMIAR+1])
{
    for (int i = 0; i < ROZMIAR; i++)
    {
        for (int j = 0; j < ROZMIAR; j++)
            cout << tablica[i][j] << " ";

        cout << endl;
    }
}


int maksSumaKwadratu(int Kwadrat[][ROZMIAR+1], vector<int>& sciezka)
{
    // Dozwolone ruchy - w dol i w prawo
    int row = 0;
    int col = 0;
    int suma = Kwadrat[0][0];
    sciezka.push_back(Kwadrat[0][0]);

    while (row < ROZMIAR - 1 || col < ROZMIAR - 1)
    {
        if (Kwadrat[row+1][col] > Kwadrat[row][col+1])
            row += 1;
        else
            col += 1;
        
        suma += Kwadrat[row][col];
        sciezka.push_back(Kwadrat[row][col]);
    }

    return suma;
}


int main()
{
    srand(time(NULL));

    int Kwadrat[ROZMIAR+1][ROZMIAR+1];
    wylosujTablice(Kwadrat);
    wypiszTablice(Kwadrat);
    vector<int> sciezka;

    cout << "Maksymalna suma: " << maksSumaKwadratu(Kwadrat, sciezka) << endl;
    cout << "Sciezka: ";
    for (int i = 0; i < sciezka.size(); i++)
        cout << sciezka[i] << " ";

    return 0;
}
