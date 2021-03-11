#include <iostream>

using namespace std;
 
void RozkladNaCzynnikiPierwsze()
{
   	int input;
   	int divider = 2;
   	cout << "Podaj liczbe naturalna \n";
   	cin >> input;
   	
   	while (input > 1)
   	{
   		if (input % divider == 0)
   		{
   			cout << divider << " ";
   			input = input / divider;
		}
		else
		{
			divider++;
		}
	}
   	
}
