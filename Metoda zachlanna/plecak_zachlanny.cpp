#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

// Ogólny problem plecakowy 
// Nieograniczona liczba przedmiotów

struct przedmiot
{
    int wartosc;
    int waga;
};


bool porownaj(przedmiot a, przedmiot b)
{
    // Sortowanie po ilorazie wartosci do wagi
    return (float(a.wartosc) / a.waga > float(b.wartosc) / b.waga);
}


int plecak(vector<przedmiot> przedmioty, vector<int>& ilosci, int wagaMax)
{
    // Algorytm nie zawsze znajduje optymalną wartość
    // Wykorzystanie metody zachłannej
    int wartosc = 0;
    for (int i = 0; i < przedmioty.size(); i++)
    {
        ilosci[i] = wagaMax / przedmioty[i].waga;
        wagaMax = wagaMax % przedmioty[i].waga;
        wartosc += ilosci[i] * przedmioty[i].wartosc;
    }

    return wartosc;
}


int main()
{
    const string SCIEZKA = "plecak.txt";
    vector<przedmiot> przedmioty;
    ifstream plik(SCIEZKA);

    while (!plik.eof())
    {
        przedmiot temp;
        plik >> temp.wartosc >> temp.waga;
        przedmioty.push_back(temp);
    }
    plik.close();
    sort(przedmioty.begin(), przedmioty.end(), porownaj);

    int wagaMax;
    vector<int> ilosci;
    ilosci.resize(przedmioty.size());

    cout << "Jaka jest maksymalna waga?";
    cin >> wagaMax;
    int wartoscMax = plecak(przedmioty, ilosci, wagaMax);
    cout << "Maksymalna wartosc: " << wartoscMax;


    return 0;
}