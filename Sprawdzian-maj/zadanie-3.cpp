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

int main()
{
    srand(time(NULL));
    vector<int> numbers;
    getRandom(numbers);
    print(numbers);

    return 0;
}