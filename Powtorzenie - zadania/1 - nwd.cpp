#include <iostream>
#include <vector>

using namespace std;

int _nwd(int a, int b)
{
    while (a != 0 && b != 0)
    {
        if (a > b)
        {
            a = a % b;
        }
        else if (b > a)
        {
            b = b % a;
        }
    }

    return max(a, b);
}

int NWD(vector<int> liczby)
{
    int nwd = _nwd(liczby[0], liczby[1]);
    for (int i = 2; i < liczby.size(); i++)
    {
        nwd = _nwd(nwd, liczby[i]);
    }

    return nwd;
}

int test()
{
    if (NWD({12, 36, 16}) != 4) return 1;
    if (NWD({14, 28, 4, 6}) != 2) return 2;
    return 0;
}

int main()
{
    cout << test() << endl;
    int ileLiczb;
    vector<int> liczby;

    cout << "Ile liczb: ";
    cin >> ileLiczb;

    liczby.resize(ileLiczb);
    for (int i = 0; i < ileLiczb; i++)
    {
        cin >> liczby[i];
    }
    cout << "Liczby wczytane" << endl;

    cout << "NWD - " << NWD(liczby);

    return 0;
}