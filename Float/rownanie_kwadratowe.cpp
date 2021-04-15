#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a, b, c;
    double x1, x2;

    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;

    double delta = b*b - 4*a*c;

    if (delta < 0){
        cout << "Brak pierwiastków";
        return 0;
    }

    // Korzystajac z wzorow viete'a
    double sqrtDelta = sqrt(delta);
    if (b > 0){
        x1 = (-b - sqrtDelta)/(2*a);
    }
    else {
        x1 = (-b + sqrtDelta)/(2*a);
    }

    if (x1 != 0) {
        x2 = c/(a*x1);
    }
    else {
        x2 = 0;
    }

    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;

    return 0;
}

// float a, b, c;

//     cout << "a = ";
//     cin >> a;
//     cout << "b = ";
//     cin >> b;
//     cout << "c = ";
//     cin >> c;

//     float delta = b*b - 4*a*c;

//     if (delta < 0){
//         cout << "Brak pierwiastków";
//         return 0;
//     }

//     float sqrtDelta = sqrt(delta);
//     float x1 = (-b + sqrtDelta)/(2*a);
//     float x2 = (-b - sqrtDelta)/(2*a);

//     cout << "x1 = " << x1 << endl;
//     cout << "x2 = " << x2 << endl;

//     return 0;

// a = 1
// b = 10000
// c = 1
// x1 = 0
// x2 = -10000