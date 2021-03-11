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

void QuickSort(int A[], int p, int k)
// Lepsza z³o¿onoœæ pamiêciowa
{
	int i, j, pivot;

	while (p < k)
	{
		i = p;
		j = k;
		pivot = A[(p + k) / 2];

		while (i <= j)
		{
			while (A[i] < pivot)
				i++;

			while (A[j] > pivot)
				j--;

			if (i <= j)
			{
				swap(A[i], A[j]);
				i++;
				j--;
			}
		}

		if (j - p < k - i)
		{
			QuickSort(A, p, j);
			p = i;
		}
		else
		{
			QuickSort(A, i, k);
		}
	}

}

int main()
{
	int A[N];
	srand(time(NULL));
	Losuj(A);
	Wypisz(A);

	// ???
}