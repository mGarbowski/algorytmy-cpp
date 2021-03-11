#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 10;

void Losuj(int A[])
{
	for (int i = 0; i < N; i++)
	{
		A[i] = rand() % 100;
	}
}

void Wypisz(int A[])
{
	for (int i = 0; i < N; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}

bool LinSearch(int x, int A[])
{
	for (int i = 0; i < N; i++)
	{
		if (A[i] == x)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	srand(time(NULL));
	int A[N];
	Losuj(A);
	Wypisz(A);

	int x;
	cout << "Podaj liczbe x: " << endl;
	cin >> x;

	if (LinSearch(x, A))
	{
		cout << "x znajduje sie w zbiorze" << endl;
	}
	else
	{
		cout << "x nie znajduje sie w zbiorze" << endl;
	}
}