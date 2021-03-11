#include <iostream>
#include <string>

using namespace std;

string szyfrPrzestawny(string text)
{
	char temp;
	int i = 0;
	while (i < text.size() - 1)
	{
		temp = text[i];
		text[i] = text[i + 1];
		text[i + 1] = temp;

		i += 2;
	}
	return text;
}

int main()
{
	string text;
	cout << "Podaj tekst: ";
	cin >> text;

	cout << "\nZaszyfrowany tekst: " << szyfrPrzestawny(text);
}

