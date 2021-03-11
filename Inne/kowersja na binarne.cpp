#include <iostream>

using namespace std;


string DecToBin(int dec)
{
	// Rekurencyjnie zamienia liczbê w systemie dziesiêtnym
	// na liczbê w systemie binarnym i zwraca j¹ jako string

	string bin;
	
	// Przypadki bazowe
	if (dec == 0)
		return "0";
	if (dec == 1)
		return "1";
	
	// Przypadki rekurencyjne
	if (dec % 2 == 0)
		return DecToBin(dec / 2) + "0";
	else
		return DecToBin(dec / 2) + "1";
}

int main()
{
	int dec;
	cin >> dec;
	cout << DecToBin(dec);
}

