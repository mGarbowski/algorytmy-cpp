#include <iostream>

using namespace std;

int main()
{
    float x = 0.1;
    float suma = 0;
    int n = 1e5;

    for (int i = 0; i < n; i++)
    {
        suma += x;
    }

    cout << "Wynik = " << suma << endl;
    cout << "Blad = " << n*x - suma;
    return 0;
}