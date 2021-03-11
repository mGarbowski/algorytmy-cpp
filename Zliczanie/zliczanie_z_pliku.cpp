#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void zliczanieZPliku()
{
	string inputFile = "text.txt";
	string napis = "";
	int Liczniki[26];
	int i;
	char ch;

	for (i = 0; i < 26; i++)
	{
		Liczniki[i] = 0;
	}

	ifstream inputStream(inputFile);
	while (!inputStream.eof())
	{
		getline(inputStream, napis);
		for (i = 0; i < napis.size(); i++)
		{
			ch = toupper(napis[i]);
			if (ch >= 'A' && ch <= 'Z')
			{
				Liczniki[ch - 'A']++;
			}
		}
	}
	inputStream.close();

	cout << "Source file: " << inputFile << endl;
	for (i = 0; i < 26; i++)
	{
		if (Liczniki[i] != 0)
		{
			cout << char(i + 'A') << ": ";
			cout << Liczniki[i] << endl;
		}
	}
}
