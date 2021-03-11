// Implementacja stosu z wykorzystaniem zmiennej typu string
// Jeden stos w postaci zmiennej globalnej
// Wszystkie funkcje odwołują się bezpośrednio do globalnego stosu


#include <iostream>
#include <string>

using namespace std;

string stack = "";

void push(char element)
{
    stack += element;
}

// Zarówno zwraca wierzchołek i zdejmuje go ze stosu
char pop()
{
    if (stack.size() == 0)
    {
        return '?';  // Domyślna wartość błędu
    }

    char top = stack[stack.size()-1];

    // usunięcie
    string temp = "";
    for (int i = 0; i < stack.size()-1; i++)
    {
        temp += stack[i]; 
    }
    stack = temp;
    
    return top;
}

bool empty()
{
    return (stack.size() == 0);
}

int main()
{
    // Test


    cout << "Stos pusty: " << empty() << endl;

    push('a');
    push('b');
    push('c');

    cout << "Stos pusty: " << empty() << endl;
    cout << "Stos: " << stack << endl;
    cout << "Wierzchoek: " << pop() << endl;
    cout << "Stos: " << stack << endl;
    cout << "Wierzchoek: " << pop() << endl;
    cout << "Wierzchoek: " << pop() << endl;
    cout << "Wierzchoek: " << pop() << endl;

    return 0;
}