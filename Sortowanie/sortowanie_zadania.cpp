#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 10;

int SumaCyfr(int n)
{
	int suma = 0;
	while (n != 0)
	{
		suma += n % 10;
		n = n / 10;
	}
	return suma;
}

void Sortuj(int A[], int N)
{
	int i, j, m, temp;

	for (i = 0; i < N - 1; i++)
	{
		m = i;
		for (j = i + 1; j < N; j++)
		{
			if (SumaCyfr(A[j]) < SumaCyfr(A[m]))
			{
				m = j;
			}
		}
		temp = A[i];
		A[i] = A[m];
		A[m] = temp;
	}
}

void Losuj1(int A[])
{
	for (int i = 0; i < N; i++)
	{
		A[i] = 10 + rand() % 90;
	}
}

void Losuj2(int A[])
{
	for (int i = 0; i < N; i++)
	{
		A[i] = rand();
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

int main()
{
	int A[N];
	srand(time(NULL));

	//Losuj1(A)
	Losuj2(A);
	Wypisz(A);

	Sortuj(A, N);
	Wypisz(A);
}