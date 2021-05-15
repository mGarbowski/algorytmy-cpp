#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int ROZMIAR = 15;
int ciag[ROZMIAR];

void wylosuj()
{
    for (int i = 0; i < ROZMIAR; i++)
        ciag[i] = (rand() % 50) - 25;
}

void wypiszCaly()
{
    for (int i = 0; i < ROZMIAR; i++)
        cout << ciag[i] << " ";
    cout << endl;
}

void wypiszPodciag(int start, int sumaMax)
{
    int suma = 0;
    int i = start;
    while (suma != sumaMax)
    {
        cout << ciag[i] << " ";
        suma += ciag[i];
        i++;
    }

    cout << endl;
}

void PSMS(int& start, int& suma)
{
    // Podciąg spójny o maksymalnej sumie
    start = 0;
    suma = 0;
    int startMax = 0;
    int sumaMax = 0;

    for (int i = 0; i < ROZMIAR; i++)
    {
        if (suma + ciag[i] > 0)
        {
            suma += ciag[i];
            if (suma > sumaMax)
            {
                sumaMax = suma;
                startMax = start;
            }
        }
        else
        {
            start = i+1;
            suma = 0;
        }
    }

    start = startMax;
    suma = sumaMax;
}

int main()
{
    srand(time(NULL));
    wylosuj();
    wypiszCaly();

    int start;
    int suma;
    PSMS(start, suma);
    //wypiszPodciag(start, suma);
    cout << "Poczatek na indeksie " << start << endl;
    cout << "Maksymalna suma " << suma << endl;

    return 0;
}