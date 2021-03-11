#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 10;

void Losuj(int A[])
{
	for (int i = 0; i < N; i++)
	{
		A[i] = rand() % 50;
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

void BubbleSort(int A[], int N)
{
	int i, j, temp;

	for (i = 1; i < N; i++)
	{
		for (j = 0; j < N - 1; j++)
		{
			if (A[j] > A[j + 1])
			{
				temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
				//Wypisz(A);
			}
		}
	}

}

void InsertionSort(int A[], int N)
{
	int i, j;

	for (i = 2; i < N; i++)
	{
		A[0] = A[i];
		j = i - 1;
		while (A[j] > A[0])
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = A[0];
		//Wypisz(A);
	}
	A[0] = 0;
}

void SelectionSort(int A[], int N)
{
	int i, j, m, temp;

	for (i = 0; i < N-1; i++)
	{
		m = i;
		for (j = i + 1; j < N; j++)
		{
			if (A[j] < A[m])
			{
				m = j;
			}
		}
		temp = A[i];
		A[i] = A[m];
		A[m] = temp;
		//Wypisz(A);
	}
}

int main()
{
	int A[N];
	srand(time(NULL));
	Losuj(A);
	Wypisz(A);

	// Sortowanie b¹belkowe
	//BubbleSort(A, N);

	// Sortowanie przez wstawianie
	//A[0] = 0;
	//InsertionSort(A, N);


	// Sortowanie przez wybieranie
	SelectionSort(A, N);

	Wypisz(A);
}