#include <iostream>
#include <string>
#include <cctype>

using namespace std;


string TylkoLitery(string zdanie)
{
    int i = 0;
    while (i < zdanie.size())
    {
        if (toupper(zdanie[i]) < 'A' || toupper(zdanie[i]) > 'Z')
            zdanie.erase(i, 1);  // Usuniecie 1 znaku na pozycji i
        else
            i++;
    }

    return zdanie;
}


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


int main()
{
    string zdanie;
    cout << "Podaj zdanie" << endl;
    getline(cin, zdanie);  // Wczytanie calej linii

    cout << Palindrom(TylkoLitery(zdanie));

    return 0;
}