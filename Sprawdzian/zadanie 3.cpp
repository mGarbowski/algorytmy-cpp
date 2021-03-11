// Miko³aj Garbowski 2e
// zadanie 3

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int n = 20;

int NajmniejszyCzynnikPierwszy(int input)
{
    int divisor = 2;
    if (input == 1)
        return 1;

    while (input > 1)
    {
        if (input % divisor == 0)
        {
            return divisor;
            input = input / divisor;
        }
        else
        {
            divisor++;
        }
    }

}


void Losuj(int A[])
{
    for (int i = 0; i < n; i++)
    {
        A[i] = (rand() % 1000) + 1;
    }
}


void Wypisz(int A[])
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}


void Sortuj(int A[])
{
    int i, j, m, temp;

    for (i = 0; i < n - 1; i++)
    {
        m = i;
        for (j = i + 1; j < n; j++)
        {
            if (NajmniejszyCzynnikPierwszy(A[j]) < NajmniejszyCzynnikPierwszy(A[m]))
            {
                m = j;
            }
        }
        temp = A[i];
        A[i] = A[m];
        A[m] = temp;
    }
}


int main()
{
    srand(time(NULL));
    int tablica[n];
    Losuj(tablica);
    cout << "Tablica: \n";
    Wypisz(tablica);

    Sortuj(tablica);
    cout << "\nPosortowana po najmniejszym czynniku pierwszym: \n";
    Wypisz(tablica);

    return 0;
}

