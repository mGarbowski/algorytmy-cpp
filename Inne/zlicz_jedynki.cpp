#include <iostream>

using namespace std;
 
int ZliczJedynki()
{
   	int x, ileJedynek;
   	cout<<"x = ";
   	cin>>x;
   	ileJedynek = 0;
   	while (x>0)
	{
   		//cout<<x%2;
   		if(x%2==1)
		{
   			ileJedynek = ileJedynek + 1;
		}
   		x=x/2;
	}
	return ileJedynek;
}
