#include <iostream>
#include <vector>

using namespace std;

void wczytajWielomian(vector<float> &wspolczynniki)
{
    int stopien;
    cout << "Stopien wielomianu = ";
    cin >> stopien;

    wspolczynniki.resize(stopien+1);

    for (int i = stopien; i >= 0; i--){
        cout << "a_" << i << " = ";
        cin >> wspolczynniki[i];
    }
}

float wartoscWielomianu(vector<float> wspolczynniki, float x)
{
    float wynik = 0;
    float potega = 1;

    for (int i = 0; i < wspolczynniki.size(); i++){
        wynik += wspolczynniki[i] * potega;
        potega = potega * x;
    }

    return wynik;
}


float schematHornera(vector<float> wspolczynniki, float x)
{
    // Wykonuje 2 razy mniej operacji mnozenia niz wartoscWielomianu()
    // n mnozen oraz n dodawan

    int stopien = wspolczynniki.size() - 1;
    float wynik = wspolczynniki[stopien];

    for (int i = stopien-1; i >= 0; i--){
        wynik = wynik * x + wspolczynniki[i];
    }

    return wynik;
}


int main()
{
    vector<float> wielomian;
    wczytajWielomian(wielomian);

    float x;
    cout << "x = ";
    cin >> x;

    cout << "W(" << x << ") = " << schematHornera(wielomian, x);

    // for (int i = wspolczynniki.size()-1; i >= 0; i--){
    //     cout << wspolczynniki[i] << "x^" << i << " + ";
    // }

    return 0;
}