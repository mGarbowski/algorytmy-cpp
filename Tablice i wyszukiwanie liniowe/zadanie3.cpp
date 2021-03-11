#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	int rzuty;
	cout << "Ile rzutow symulowac: " << endl;
	cin >> rzuty;

	int wynik[6] = { 0,0,0,0,0,0 };
	srand(time(NULL));

	//Symulacja rzutow i zliczenie
	for (int i = 0; i < rzuty; i++)
	{
		int oczka = rand() % 6;
		wynik[oczka]++;
	}

	//Wypisanie
	for (int i = 0; i < 6; i++)
	{
		cout << "Oczek: " << i + 1 << "  Razy: " << wynik[i] << endl;
	}
}