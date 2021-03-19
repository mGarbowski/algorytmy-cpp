#include <iostream>
#include <vector>

using namespace std;

void trojkatPascala(int n)
{
    // Wypisuje n pierwszych wierszy trójkąta Pascala

    vector<int> poprzedni {1, 1};  // Wartości wiersza drugiego
    vector<int> temp;
    int liczba;

    if (n >= 1)
        cout << "1" << endl;
    if (n >= 2)
        cout << "1 1" << endl;

    for (int j = 2; j < n; j++)
    {
        temp.clear();

        cout << "1 ";
        temp.push_back(1);

        for (int i = 0; i < poprzedni.size() - 1; i++)
        {
            liczba = poprzedni[i] + poprzedni[i+1];
            temp.push_back(liczba);
            cout << liczba << " ";
        }

        cout << "1" << endl;
        temp.push_back(1);
        poprzedni = temp;
    }
}

int main()
{
    int n;
    cout << "Ile wierszy? ";
    cin >> n;

    trojkatPascala(n);

    return 0;
}