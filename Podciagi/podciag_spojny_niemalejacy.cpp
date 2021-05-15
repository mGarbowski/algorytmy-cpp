#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int ROZMIAR = 30;
int ciag[ROZMIAR];

void wylosuj()
{
    for (int i = 0; i < ROZMIAR; i++)
        ciag[i] = (rand() % 200) - 100;  // Od -100 do 99
}

void wypiszCaly()
{
    for (int i = 0; i < ROZMIAR; i++)
        cout << ciag[i] << " ";
    cout << endl;
}

void wypiszPodciag(int start, int rozmiar)
{
    for (int i = start; i < start + rozmiar; i++)
        cout << ciag[i] << " ";
    cout << endl;
}

void NSPNM(int& start, int& rozmiar)
{
    // Najdłuższy spójny podciąg niemalejący
    start = 0;
    rozmiar = 1;
    int startMax = 0;
    int rozmiarMax = 1;

    for (int i = 1; i < ROZMIAR; i++)
    {
        if (ciag[i] >= ciag[i-1])
        {
            rozmiar += 1;
            if (rozmiar > rozmiarMax)
            {
                rozmiarMax = rozmiar;
                startMax = start;
            }
        }
        else
        {
            start = i;
            rozmiar = 1;
        }
    }
    rozmiar = rozmiarMax;
    start = startMax;
}

int main()
{
    srand(time(NULL));
    wylosuj();
    wypiszCaly();

    int start;
    int rozmiar;
    NSPNM(start, rozmiar);
    cout << "Najdluzszy podciag niemalejacy" << endl;
    wypiszPodciag(start, rozmiar);
    cout << "Poczatek w indeksie " << start << endl;
    cout << "Dlugosc " << rozmiar << endl;

    return 0;
}