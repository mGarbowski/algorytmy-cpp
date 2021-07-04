// Wydawanie reszty metoda programowania dynamicznego

#include <vector>
#include <iostream>

using namespace std;

const int ILE_NOMINALOW = 3;
const int NOMINALY[] = {1, 5, 7};
const int KWOTA = 8;

int ileMonet(int Reszta[])
{
    int ileMonet[KWOTA + 1];
    ileMonet[0] = 0;
    for (int i = 1; i <= KWOTA; i++)
        ileMonet[i] = KWOTA + 1;  // Pierwszy otrzymany wynik będzie musiał być lepszy

    int rozkladMonet[KWOTA + 1][ILE_NOMINALOW];
    for (int i = 0; i < ILE_NOMINALOW; i++)
        rozkladMonet[0][i] = 0;  // Zerowanie pierwszego wiersza dla kwoty 0

    for (int aktKwota = 1; aktKwota <= KWOTA; aktKwota++) {
        for (int nNominal = 0; nNominal < ILE_NOMINALOW; nNominal++) {
            int aktNominal = NOMINALY[nNominal];
            if (aktNominal <= aktKwota) {
                if (ileMonet[aktKwota - aktNominal] + 1 < ileMonet[aktKwota]) {  // Czy liczba monet dla aktualnego nominału jest bardziej optymalna
                    ileMonet[aktKwota] = ileMonet[aktKwota - aktNominal] + 1;

                    for (int nominal = 0; nominal < ILE_NOMINALOW; nominal++) 
                        rozkladMonet[aktKwota][nominal] = rozkladMonet[aktKwota - aktNominal][nominal];
                    
                    rozkladMonet[aktKwota][aktNominal]++;
                }
            }
        }
    }

    for (int i = 0; i < ILE_NOMINALOW; i++)
        Reszta[i] = rozkladMonet[KWOTA][i]; // Przepisanie wyniku

    return ileMonet[KWOTA];
}

int main()
{
    int Reszta[ILE_NOMINALOW];
    int ile = ileMonet(Reszta);

    for (int i = 0; i < ILE_NOMINALOW; i ++) {
        cout << NOMINALY[i] << ": " << Reszta[i] << endl;
    } 

    return 0;

}