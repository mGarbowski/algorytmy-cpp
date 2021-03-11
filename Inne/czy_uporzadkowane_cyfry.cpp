#include <iostream>

using namespace std;
// Sprawdza czy cyfry podanego x s¹ uporz¹dkowane malej¹co
void CzyUporzadkowana()
{
	int x, ost;
	bool wynik = true;
   	cout << "x = ";
   	cin >> x;
   	
   	ost = x % 10;
   	x = x / 10;
   	
   	while (x > 0 && wynik == true){
   		if (x % 10 > ost){
   			ost = x % 10;
   			x = x / 10;
		   }
		else{
			wynik = false;
			}
	   }
	if (wynik == true){
		cout << "Tak";
	}
	else {
		cout << "Nie";
	}
}
