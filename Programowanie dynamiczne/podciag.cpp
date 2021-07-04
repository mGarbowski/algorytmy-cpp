#include <iostream>

using namespace std;

const int MAX_LEN = 20;

int main() 
{
    int len[MAX_LEN + 1][MAX_LEN + 1];
    string textFirst, textSecond;
    cout << "Pierwszy napis: ";
    cin >> textFirst;
    cout << "Drugi napis: ";
    cin >> textSecond;

    int lenFirst = textFirst.size();
    int lenSecond = textSecond.size();

    for (int i = 0; i < lenFirst; i++)
        len[i][0] = 0;
    for (int i = 0; i < lenSecond; i++)
        len[0][i] = 0;

    for (int i = 1; i <= lenFirst; i++) {
        for (int j = 1; j <= lenSecond; j++) {
            if (textFirst[i-1] == textSecond[j-1])
                len[i][j] = len[i-1][j-1] + 1;
            else
                len[i][j] = max(len[i-1][j], len[i][j-1]);
        }
    }

    cout << "Najwieksza dlugosc: " << len[lenFirst][lenSecond] << endl;

    int i = lenFirst;
    int j = lenSecond;
    string sub = "";

    while (i > 0 && j > 0)
    {
        if (textFirst[i-1] == textSecond[j-1])
        {
            sub = textFirst[i-1] + sub;
            i--;
            j--;
        }
        else if (len[i][j-1] > len[i-1][j])
        {
            j--;
        }
        else
        {
            i--;
        }
    }
    cout << "Podciag: " << sub;
   
    return 0;
}