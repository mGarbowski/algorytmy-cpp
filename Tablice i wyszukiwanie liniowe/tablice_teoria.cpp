#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 100;

void Losuj(int A[])
{
	for (int i = 0; i < N; i++)
	{
		A[i] = rand() % 20; //dzielenie modulo gwarantuje liczbe w zakresie do 100
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

bool BinarySearch(int A[], int x)
{
	int min = 0;
	int mid = 0;
	int max = N - 1;

	for (int i = 0; i < N; i++)
	{
		mid = (min + max) / 2;
		if (A[mid] < x)
		{
			min = mid;
		}
		else if (A[mid] > x)
		{
			max = mid;
		}
		else if (A[mid] == x)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	int A[N];
	srand(time(NULL)); //ustawienie seedu funkcji rand
	Losuj(A);
	Wypisz(A);
}