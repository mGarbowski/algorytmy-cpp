#include <iostream>
#include <stack>

using namespace std;


bool czySparowane(string wejscie)
{
    // dozwolone
    // (), {}, []
    stack<char> otwarte;

    for (int i = 0; i < wejscie.size(); i++)
    {
        if (wejscie[i] == '('
         || wejscie[i] == '['
         || wejscie[i] == '{')
        {
            otwarte.push(wejscie[i]);
        }

        else if (otwarte.empty())
        {
            return false;
        }

        else if (wejscie[i] == ')')
        {
            if (otwarte.top() == '('){
                otwarte.pop();
                continue;
            }
            else {
                return false;
            }
        }
        else if (wejscie[i] == ']')
        {
            if (otwarte.top() == '['){
                otwarte.pop();
                continue;
            }
            else {
                return false;
            }
        }
        else if (wejscie[i] == '}')
        {
            if (otwarte.top() == '{'){
                otwarte.pop();
                continue;
            }
            else {
                return false;
            }
        }
    }

    if (otwarte.empty()){
        return true;
    }
    else {
        return false;
    }
}

int test()
{
    if (czySparowane("()") != true) return 1;
    if (czySparowane("([{}])") != true) return 2;
    if (czySparowane("(") != false) return 3;
    if (czySparowane("][") != false) return 4;
    if (czySparowane("{{[]})") != false) return 5;
    if (czySparowane("") != true) return 6;
    if (czySparowane("}") != false) return 7;

    return 0;
}

int main()
{
    string wejscie;
    cout << "Dozwolone (), {}, []" << endl;
    cout << "Podaj napis zlozony z nawiasow" << endl;
    cin >> wejscie;

    if (czySparowane(wejscie)){
        cout << "Nawiasy sa sparowane";
    }
    else {
        cout << "Nawiasy NIE sa sparowane";
    }

    return 0;
}