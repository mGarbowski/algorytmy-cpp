#include <iostream>

using namespace std;

const int N_WYRAZOW = 10;
int silnia[2*N_WYRAZOW];

float cosinus(float x)
{
    silnia[0] = 1;
    float wynik = 1;
    float potega = 1;

    for (int i = 1; i < 2 * (N_WYRAZOW-1); i++)
    {
        potega = potega * x;
        silnia[i] = silnia[i-1] * i;
        
        if (i % 4 == 0)
        {
            wynik += potega / silnia[i];
        }
        else if (i % 2 == 0)
        {
            wynik -= potega / silnia[i];
        }
    }

    return wynik;
}

int main()
{
    float x;
    cout << "x = ";
    cin >> x;
    cout << "cos(x) = " << cosinus(x) << endl;

    return 0; 
}