#include <iostream>

using namespace std;
int nIteracji = 10;

int main()
{
    float wynik = 1;
    float silnia = 1;
    int iteracje = 1;
    int n = 2;
    while (iteracje < nIteracji)
    {
        silnia = -silnia * n * (n+1);
        n += 2;
        wynik += 1 / silnia;
        iteracje += 1;
    }

    cout << "Wynik = " << wynik << endl;

    return 0;
}