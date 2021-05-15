#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

struct proba
{
    int startGodzina;
    int dlugoscMinuty;
};


bool porownaj(proba a, proba b)
{
    // Sortowanie po czasie zakonczenia
    return (a.startGodzina * 60 + a.dlugoscMinuty < b.startGodzina * 60 + b.dlugoscMinuty);
}


int maksLiczbaProb(vector<proba> Proby)
{
    int ile = 1;
    int poprzednia = 0;

    for (int i = 1; i < Proby.size(); i++)
    {
        // start a >= koniec b
        if (Proby[i].startGodzina * 60 >= Proby[poprzednia].startGodzina*60 + Proby[poprzednia].dlugoscMinuty)
        {
            ile += 1;
            poprzednia = i;
        }
    }

    return ile;
}

int main()
{

    const string PATH = "sala.txt";
    vector<proba> Proby;
    ifstream plik(PATH);

    while (!plik.eof())
    {
        proba tmp;
        plik >> tmp.startGodzina >> tmp.dlugoscMinuty;
        Proby.push_back(tmp);
    }
    plik.close();
    sort(Proby.begin(), Proby.end(), porownaj);
    cout << "Maksymalna liczba prob: " << maksLiczbaProb(Proby);

    return 0;
}

// Program zlicza ile prob moze odbyc sie na sali na podstawie danych z pliku
// o podanych godzinach rozpoczecia i czasie trwania