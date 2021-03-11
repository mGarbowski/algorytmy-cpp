#include <iostream>

using namespace std;
 
void CzyPierwsza()
{
	/*
	int d=2;
	bool prime = true;
	int x;
	cout<<"Podaj liczbe"<<"\n";
	cin>>x;
	if (x == 0 || x == 1) prime = false;
	while(d*d < x){
		if (x%d==0){
			prime=false;
		}
		d++;
		if (d*d==x){
			prime=false;
		}
	}
	if (prime){
		cout << "Liczba pierwsza";
	}
	else {
		cout << "Nie jest liczb¹ pierwsz¹";
	}
	*/
	
	//deklaracja i definicja zmiennych
	int input;
	int divider = 5;
	bool prime;
	
	cout << "Podaj liczbe naturalna" << "\n";
	cin >> input;
	
	//wykluczenie 0, 1, liczb parzystych, podzielnych przez 3
	prime = input > 1;
	if (input > 2 && input % 2 == 0)
	{
		prime = false;
	}
	if (input > 3 && input % 3 == 0)
	{
		prime = false;
	}
	
	//glowny algorytm sprawdzajacy czy liczba jest pierwsza
	while (prime && divider * divider <= input)
	//sprawdzane dzielniki mniejsze od sqrt(input)
	{
		if (input % divider == 0)
		{
			prime = false;
		}
		//sprawdzenie 2 liczb z ciagu 6 ze wzgledu na wlasciwosci podzielnosci
		else if (input % (divider + 2) == 0)
		{
			prime = false;
		}
		else
		{
			//przeskok do kolejnego ciagu 6 liczb
			divider += 6;
		}
	}
	
	//wypisanie wyniku
	if (prime == true)
	{
		cout << "Liczba pierwsza";
	}
	else
	{
		cout << "Liczba nie jest pierwsza";
	}
	
	
}
