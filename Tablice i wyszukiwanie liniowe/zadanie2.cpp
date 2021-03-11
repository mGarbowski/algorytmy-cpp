#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 100;

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

int GetMin(int A[])
{
	int min = A[0];
	for (int i = 0; i < N; i++)
	{
		if (min > A[i])
		{
			min = A[i];
		}
	}
	return min;
}

int GetMax(int A[])
{
	int max = 0;
	for (int i = 0; i < N; i++)
	{
		if (max < A[i])
		{
			max = A[i];
		}
	}
	return max;
}

int main()
{
	srand(time(NULL));

	int A[N];
	Losuj(A);
	Wypisz(A);

	cout << "Minimum: " << GetMin(A) << endl;
	cout << "Maksimum: " << GetMax(A) << endl;
}