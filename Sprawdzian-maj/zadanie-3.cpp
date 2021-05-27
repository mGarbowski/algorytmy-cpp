#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

void getRandom(vector<int>& numbers, int size)
{
    numbers.resize(size);

    for (int i = 0; i < size; i++)
    {
        numbers[i] = rand() % 100;
    }
}

void print(vector<int> numbers)
{
    for (int i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << " ";
    }
}

void shiftArray(vector<int>& arr, int shift)
{
    int temp;
    for (int i = 0; i < shift; i++)
    {
        temp = arr[0];
        for (int j = 0; j < arr.size()-1; j++)
        {
            arr[j] = arr[j+1];
        }
        arr[arr.size()-1] = temp;
    }
}

int main()
{
    srand(time(NULL));
    vector<int> numbers;
    int size;
    int shift;

    cout << "Podaj dlugosc: ";
    cin >> size;
    cout << "O ile w lewo przesunac: ";
    cin >> shift;

    getRandom(numbers, size);
    print(numbers);

    shiftArray(numbers, shift);
    cout << "Po przesunieciu:" << endl;
    print(numbers);

    return 0;
}