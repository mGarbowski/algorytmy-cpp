#include <iostream>

using namespace std;

// Porownywanie z wartoscia epsilon zamiast z 0 dla unikniecia bledow numerycznych
const float EPS = 0.000001;

float f(float x)
{
    return x*x*x - 6*x*x + 3*x + 10;
}


int main()
{
    // Szukanie miejsca zerowego w danym przedziale metoda bisekcji (wyszukiwanie binarne)

    float low, mid, high;

    cout << "Dolna granica przedzialu = ";
    cin >> low;
    cout << "Gorna granica przedzialu = ";
    cin >> high;


    if (f(low) * f(high) < 0)
    {
        mid = (low + high) / 2;

        while ((abs(f(mid)) > EPS) && (high-low > EPS))
        {
            if (f(low) * f(mid) < 0)
            {
                high = mid;
            }
            else 
            {
                low = mid;
            }

            mid = (low + high) / 2;
        }

        cout << "Miejsce zerowe: " << mid;
    }
    else 
    {
        cout << "Nieprawidlowy przedzial";
    }

    return 0;
}