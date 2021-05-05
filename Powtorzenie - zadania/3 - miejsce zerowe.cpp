#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
const float EPSILON = 0.001;

float oblicz(vector<int> wielomian, float x)
{
    int stopien = wielomian.size() - 1;
    float wynik = wielomian[stopien];

    for (int i = stopien-1; i >= 0; i--)
    {
        wynik = wynik * x + wielomian[i];
    }
}

float pierwiastek(vector<int> wielomian, float dolna, float gorna)
{
    if (oblicz(wielomian, dolna) * oblicz(wielomian, gorna) > 0)
    {
        return NAN;
    }

    float mid = (gorna + dolna) / 2;
    while ( (abs(oblicz(wielomian, mid)) > EPSILON) && (abs(gorna - dolna) > EPSILON) )
    {
        if (oblicz(wielomian, mid) * oblicz(wielomian, dolna) < 0)
        {
            gorna = mid;
        }
        else
        {
            dolna = mid;
        }

        mid = (gorna + dolna) / 2; 
    }

    return mid;
}

int test()
{
    if (oblicz({1, 2, 3}, 2) != 17) return 1;
    if (abs(pierwiastek({3 -2, -4, 1}, -2, 0) - (-1)) < 0) return 2;
    if (abs(pierwiastek({3 -2, -4, 1}, 1, 2) - (1.434)) < 0) return 3;
    if (abs(pierwiastek({3 -2, -4, 1}, 0, 1) - (0.23)) < 0) return 4;
    if (!isnan(pierwiastek({3 -2, -4, 1}, 2, 3))) return 5;
    return 0;
    
}

int main()
{
    // cout << test();
    int stopien;
    vector<int> wielomian;
    float dolna, gorna;

    cout << "Stopien: ";
    cin >> stopien;

    wielomian.resize(stopien + 1);
    for (int i = stopien; i >= 0; i--)
    {
        cout << "a" << i << " = ";
        cin >> wielomian[i];
    }

    cout << "Dolna granica przedzialu: ";
    cin >> dolna;
    cout << "Gorna granica przedzialu: ";
    cin >> gorna;


    cout << pierwiastek(wielomian, dolna, gorna);

    return 0;
}