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


void WypiszPalindromy(string zdanie)
{
    int i;
    string wyraz;
    zdanie += ' ';

    while (zdanie.size() > 0)
    {
        i = zdanie.find(' ');

        if (i > 0)
        {
            wyraz = zdanie.substr(0, i);
            if (Palindrom(wyraz))
                cout << wyraz << endl;
        }

        zdanie.erase(0, i+1);
    }
}

int main()
{
    string zdanie;
    cout << "Podaj zdanie" << endl;
    getline(cin, zdanie);

    WypiszPalindromy(zdanie);

    return 0;
}