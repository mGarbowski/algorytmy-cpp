#include <iostream>

using namespace std;


bool CzyPierwsza(int liczba)
{
    bool czyPierwsza = (liczba > 1);

    if (liczba > 2 && liczba % 2 == 0)
        czyPierwsza = false;
    if (liczba > 3 && liczba % 3 == 0)
        czyPierwsza = false;

    int dizelnik = 5;
    while (czyPierwsza && dizelnik * dizelnik <= liczba)
    {
        if (liczba % dizelnik == 0)
            czyPierwsza = false;
        else if (liczba % (dizelnik + 2) == 0)
            czyPierwsza = false;
        else
            dizelnik += 6;
    }
    
    return czyPierwsza;
}


void WypiszBlizniacze(int n)
{
    cout << 3 << " " << 5 << endl;

    int x = 5;
    int licznik = 1;
    while (licznik < n)
    {
        if (CzyPierwsza(x) && CzyPierwsza(x+2))
        {
            cout << x << " " << x+2 << endl;
            licznik++;
        }
        x += 6;
    } 
}


int main()
{
    int n;
    cout << "Ile par? ";
    cin >> n;

    WypiszBlizniacze(n);

    return 0;
}