#include <iostream>
#include <vector>

using namespace std;

vector<int> CzynnikiPierwsze(int liczba)
{
    vector<int> czynniki;
    int dzielnik = 2;

    while (dzielnik * dzielnik <= liczba)
    {
        if (liczba % dzielnik == 0)
        {
            czynniki.push_back(dzielnik);
            liczba = liczba / dzielnik;
        }
        else
        {
            dzielnik++;
        }
    }
    czynniki.push_back(liczba);

    return czynniki;
}

int main()
{
    int n;
    cout << "n = ";
    cin >> n;
    vector<int> czynniki = CzynnikiPierwsze(n);

    for (int i = 0; i < czynniki.size()-1; i++)
        cout << czynniki[i] << " * ";
    cout << czynniki[czynniki.size()-1];
    
    return 0;
}