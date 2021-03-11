#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

void ZliczWystapieniaLiter(string wyraz, int liczniki[])
{
	// Wyzerowanie tablicy
	for (size_t i = 0; i < 26; i++)
	{
		liczniki[i] = 0;
	}
	// Zliczenie wystapienia liter
	for (size_t i = 0; i < wyraz.size(); i++)
	{
		liczniki[wyraz[i] - 'a']++;
	}
}

bool CzyAnagram(string wyraz1, string wyraz2)
{
	// Z³o¿onoœæ zale¿y od d³ugoœci alfabetu
	// Zaoszczêdzenie czasu kiedy wyrazy s¹ ró¿nej d³ugoœci
	if (wyraz1.size() != wyraz2.size()) 
	{
		return false;
	}

	int liczniki1[26], liczniki2[26];
	ZliczWystapieniaLiter(wyraz1, liczniki1);
	ZliczWystapieniaLiter(wyraz2, liczniki2);

	// Porównanie czêstotliwoœci wystêpowania liter
	for (size_t i = 0; i < 26; i++)
	{
		if (liczniki1[i] != liczniki2[i])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	// Wczytanie wyrazów
	string text1, text2;
	cout << "Podaj pierwsze s³owo: \n";
	cin >> text1;
	cout << "\nPodaj drugie s³owo: \n";
	cin >> text2;

	cout << CzyAnagram(text1, text2);

	return 0;
}

