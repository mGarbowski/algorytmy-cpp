#include <iostream>

using namespace std;
 
int SumaCyfr()
{
   	int x, suma;
   	cout<<"x=";
   	cin>>x;
   	suma =0;
   	while (x>0)
	{
   		suma = suma + x%10;
		x = x / 10;
	}
	return suma;
}
