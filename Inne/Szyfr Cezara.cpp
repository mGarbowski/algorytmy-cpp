#include <iostream>
#include <fstream> // wczytywanie z pliku
#include <string>

using namespace std;

const int znaki = 26;

string Cezar(string jawny, int klucz)
{
	// Szyfr cezara dla wielkich liter alfabetu ³aciñskiego
	// Ka¿da litera zostaje zamieniona na literê o klucz wiêksz¹

	string szyfrogram = "";
	int ascii;

	for (int i = 0; i < jawny.size(); i++)
		if (jawny[i] >= 'A' && jawny[i] <= 'Z')
		{
			ascii = (jawny[i] - 'A' + klucz) % znaki + 'A'; // modulo gwarantuje 'zapêtlenie' przy wyjœciu poza zakres alfabetu
			szyfrogram = szyfrogram + char(ascii);
		}
		else
		{
			szyfrogram = szyfrogram + jawny[i]; // Znaki niebêd¹ce wielkimi literami alfabetu ³aciñskiego zostaj¹ przepisane bez zmian
		}

	return szyfrogram;
}
int main()
{
	string tekstJawny;
	int klucz;

	/*
	cout << "Podaj linie tekstu:\n";
	cin >> tekstJawny;
	cout << "Podaj klucz:\n";
	cin >> klucz;

	cout << "Zaszyfrowany tekst:\n" << Cezar(tekstJawny, klucz);
	*/

	ifstream wejscie("D:\\Repos\\Informatyka\\Szyfr Cezara\\tekst_jawny.txt");
	ofstream wyjscie("D:\\Repos\\Informatyka\\Szyfr Cezara\\szyfrogram.txt");

	cout << "Podaj klucz: ";
	cin >> klucz;

	while (!wejscie.eof())
	{
		getline(wejscie, tekstJawny);
		wyjscie << Cezar(tekstJawny, klucz) << endl;
	}

	wejscie.close();
	wyjscie.close();
	cout << "Utworzono zaszyfrowany plik";

	return 0;
}

