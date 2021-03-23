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


int main()
{
    // Ile liczb palindromicznych jest w przedziale [a,b]
    int a, b, ile;

    cout << "Dolna granica ";
    cin >> a;
    cout << "Gorna granica ";
    cin >> b;

    for (int i = a; i <= b; i++)
    {
        if (Palindrom(to_string(i)))
        {
            ile++;
            cout << i << endl;
        }
    }

    cout << ile << " liczb palindromicznych";
}