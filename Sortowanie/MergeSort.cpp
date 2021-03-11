#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

const int N = 10;

void Losuj(int A[])
{
	for (int i = 0; i < N; i++)
	{
		A[i] = rand() % 100;
	}
}


void Wypisz(int A[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}


void MergeExample(int L[], int R[], int C[])
{
	int i = 0;  // Indeks pierwszej
	int j = 0;  // Indeks drugiej
	int k = 0;  // Indeks docelowej

	while (i < N && j < N)
	{
		if (L[i] < R[j])
		{
			C[k] = L[i];
			i++;
		}
		else
		{
			C[k] = R[j];
			j++;
		}

		k++;
	}

	// Po zakoñczeniu pêtli jedna z tablic zosta³a w ca³oœci przeniesiona
	// Pozosta³¹ L albo R nale¿y w ca³oœci przenieœæ do docelowej C

	// Tylko jedna z pêtli siê wykona
	while (i < N)
	{
		C[k] = L[i];
		i++;
		k++;
	}

	while (j < N)
	{
		C[k] = R[j];
		j++;
		k++;
	}
}

void Merge(int array[], int start, int mid, int end)
{
	int temp[N];	// tablica poœrednia

	int i = start;		// indeks pierwszej po³owy
	int j = mid + 1;	// indeks drugiej po³owy
	int k = 0;			// indeks tablicy docelowej

	// Przepisywanie kolejnych najmniejszych elementów 
	// z dwóch po³ówek do tablicy poœredniej
	while (i <= mid && j <= end)
	{
		if (array[i] < array[j])
		{
			temp[k] = array[i];
			i++;
		}
		else
		{
			temp[k] = array[j];
			j++;
		}

		k++;
	}

	// Przepisanie ogona
	// Wykona siê tylko jedna pêtla bo jedna po³ówka zosta³a ju¿ w ca³oœci przepisana
	while (i <= mid)
	{
		temp[k] = array[i];
		i++;
		k++;
	}

	while (j <= end)
	{
		temp[k] = array[j];
		j++;
		k++;
	}

	// Przepisanie tablicy poœredniej temp[] na pierwotn¹ array[]
	for (int i = start; i <= end; i++)
	{
		array[i] = temp[i - start];  //temp jest indeksowana od 0
	}
}


void MergeSort(int array[], int start, int end)
// Z³o¿onoœæ pesymistyczna O(n*log(n))
{
	if (start < end) 
	{
		int mid = (start + end) / 2;

		MergeSort(array, start, mid);
		MergeSort(array, mid + 1, end);

		Merge(array, start, mid, end);
	}
}


int main()
{
	int array[N];
	srand(time(NULL));

	Losuj(array);
	Wypisz(array, N);

	cout << endl;

	MergeSort(array, 0, N - 1);
	Wypisz(array, N);
	

	return 0;
}