#include <iostream>
#include <stack>

using namespace std;

int main()
{
    // Zamiana wyrażenia arytmetycznego
    // Z notacji zwyczajnej na odwrotnąnotację polską


    stack<char> stos;  // Zadeklarowanie stosu przechowującego znaki

    // stos.push(znak) - włożenie elementu znak na wierzch stosu
    // stos.pop() - zdejmuje i zwraca element z wierzchołka stosu
    // stos.top() - informacja co jest na wierzchołku
    // stos.empty() - informacja logiczna czy stos jest pusty

    string input = "";
    string output = "";

    cout << "Podaj wyrazenie w notacji tradycyjnej:\n";
    cin >> input;

    for (int i = 0; i < input.size(); i++)
    {
        // Nawiasy
        if (input[i] == '(')
        {
            stos.push('(');
        }

        else if (input[i] == ')')
        {
            while (stos.top() != '(')
            {
                // Przepisywanie zawartości stosu na wyjście 
                // aż do napotkania nawiasu otwierającego
                output += stos.top();
                stos.pop();
            }
            stos.pop();  // usunięcie nawiasu otwierającego
        }

        // Dodawanie i odejmowanie
        else if (input[i] == '+' || input[i] == '-')
        {
            while (!stos.empty() && stos.top() != '(')
            {
                output += stos.top();
                stos.pop();
            }
            stos.push(input[i]);
        }

        // Mnożenie i dzielenie
        else if (input[i] == '*' || input[i] == '/')
        {
            while (!stos.empty() && (stos.top() != '*' || stos.top() == '/'))
            {
                output += stos.top();
                stos.pop();
            }
            stos.push(input[i]);
        }

        // Pozostałe
        else
        {
            output += input[i];
        }
    }

    // Przepisanie reszty stosu
    while (!stos.empty())
    {
        output += stos.top();
        stos.pop();
    }

    cout << "\nOdwrotna notacja polska:\n" << output;
    
    return 0;
}