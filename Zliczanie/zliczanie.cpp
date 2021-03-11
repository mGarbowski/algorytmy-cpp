#include <iostream>
#include <string>

using namespace std;

void zliczanie()
{
	string napis = "";
	int Liczniki[26];
	int i;

	cout << "Podaj napis: ";
	cin >> napis;

	for (i = 0; i < 26; i++)
	{
		Liczniki[i] = 0;
	}
	

	for (i = 0; i < napis.size(); i++)
	{
		Liczniki[napis[i] - 'A']++;
	}

	for (i = 0; i < 26; i++)
	{
		if (Liczniki[i] != 0)
		{
			cout << char(i + 'A') << ": ";
			cout << Liczniki[i] << endl;
		}
	}
}
