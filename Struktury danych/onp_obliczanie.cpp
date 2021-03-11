#include <iostream>
#include <stack>

using namespace std;

int main()
{
    // Dozwolone:
    // Operacje: dodawanie, odejmowanie, mnożenie, dzielenie całkowite
    // Liczby: jednocyfrowe

    stack<char> operacje;
    stack<int> liczby;

    string wyrazenie;
    cout << "Podaj wyrazenie w odwrotnej notacji polskiej: \n";
    cin >> wyrazenie;


    // Wczytanie wszystkich znaków z wyrażenie i wepchnięcie na odpowiedni stos
    for (int i = wyrazenie.size()-1; i >= 0; i--)
    {
        if (wyrazenie[i] == '+' || 
            wyrazenie[i] == '-' ||
            wyrazenie[i] == '*' || 
            wyrazenie[i] == '/')
        {
            operacje.push(wyrazenie[i]);
        }
        else
        {
            int cyfra = (int)wyrazenie[i] - (int)'0';  // Konwersja typów i przesunięcie tak aby otrzymać int z przedziału [0,9]
            liczby.push(cyfra);
        }
    }


    int a;
    int b;
    char operacja;


    // Wyniki operacji są wpychane na stos, więc kiedy operacje.empty(),
    // to wynik wyrażenia będzie jedynym elementem na stosie liczby
    while (!operacje.empty())
    {
        // Wczytanie aktualnych liczb i operacji
        a = liczby.top();
        liczby.pop();

        b = liczby.top();
        liczby.pop();

        operacja = operacje.top();
        operacje.pop();


        // Wepchnięcie wyniku na stos
        if (operacja == '+')
        {
            liczby.push(a+b);
        }
        else if (operacja == '-')
        {
            liczby.push(a-b);
        }
        else if (operacja == '*')
        {
            liczby.push(a*b);
        }
        else if (operacja == '/')
        {
            liczby.push(a/b);
        }

    }

    int wynik = liczby.top();
    cout << wynik;

    return 0;
}