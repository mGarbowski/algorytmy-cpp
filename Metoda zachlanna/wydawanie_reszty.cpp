#include <iostream>

using namespace std;

// w groszach
const int ILE_ROZNYCH = 15;
const int nominaly[] = {50000, 20000, 10000, 5000, 2000, 1000, 500,
                        200, 100, 50, 20, 10, 5, 2, 1};


void wydajReszte(int kwota, int reszta[])
{
    kwota *= 100;  // Wszystko w groszach
    for (int i = 0; i < ILE_ROZNYCH; i++)
    {
        reszta[i] = kwota / nominaly[i]
        kwota = kwota % nominaly[i];
    }
}


int main()
{
    int reszta[ILE_ROZNYCH];
    int kwota;

    cout << "Podaj kwote [zł]: ";
    cin >> kwota;
    wydajReszte(kwota, reszta);

    for (int i = 0; i < ILE_ROZNYCH; i++)
    {
        if (nominaly[i] >= 100)
            cout << reszta[i] << " x " << nominaly[i] / 100 << "zł" << endl;
        else
            cout << reszta[i] << " x " << nominaly[i] << "gr" << endl;
    }

    return 0;
}