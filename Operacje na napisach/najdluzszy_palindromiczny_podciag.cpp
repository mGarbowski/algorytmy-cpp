#include <iostream>
#include <string>
#include <cctype>

using namespace std;


bool Palindrom(string wyraz)
{
    int i = 0;
    int j = wyraz.size()-1;

    while (i < j)
    {
        if (toupper(wyraz[i]) != toupper(wyraz[j]))
            return false;

        i++;
        j--;
    }

    return true;
}


string Najdluzszy(string wyraz)
{
    // Najdluzszy palindromiczny ciag znakow w wyrazie

    string ciag;
    string najdluzszyCiag;
    int dlugosc;

    for (int i = 0; i < wyraz.size(); i++)
    {
        for (int j = 1; j < wyraz.size() - i + 1; j++)
        {
            ciag = wyraz.substr(i, j);

            if (Palindrom(ciag))
            {
                if (ciag.size() > dlugosc)
                {
                    najdluzszyCiag = ciag;
                    dlugosc = ciag.size();
                }
            }
        }
    }

    return najdluzszyCiag;
}


int main()
{
    string wyraz;
    cout << "Wyraz: ";
    cin >> wyraz;

    cout << "Najdluzszy palindromiczny ciag znakow:\n" << Najdluzszy(wyraz);

    return 0;
}