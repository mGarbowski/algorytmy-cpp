#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 100;

void Losuj(int A[])
{
	A[0] = rand() % 20;
	for (int i = 1; i < N; i++)
	{
		A[i] = A[i - 1] + rand() % 20;
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

bool BinarySearch(int A[], int x)
{
	int min = 0;
	int mid = 0;
	int max = N - 1;

	while (min < max)
	{
		mid = (min + max) / 2;
		if (A[mid] < x)
		{
			min = mid + 1;
		}
		else
		{
			max = mid;
		}
	}
	bool result = A[min] == x;
	return result;
}
int main()
{
	int A[N];
	srand(time(NULL));
	Losuj(A);
	Wypisz(A);

	int x = 0;
	cout << "Szukana liczba: ";
	cin >> x;
	cout << BinarySearch(A, x);
}