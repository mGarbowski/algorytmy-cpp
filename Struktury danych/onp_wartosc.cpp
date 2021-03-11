#include <iostream>
#include <stack>

using namespace std;

int Oblicz(string s)
{
	stack<int> stos;
	int arg1,arg2,wynik;
	for (int i=0;i<s.size();i++)
		if (s[i]>='0' && s[i]<='9') stos.push(s[i]-'0');
		else
		{
			arg2=stos.top(); stos.pop();
			arg1=stos.top(); stos.pop();
			if (s[i]=='+') wynik=arg1+arg2;
			else if (s[i]=='-') wynik=arg1-arg2;
			else if (s[i]=='*') wynik=arg1*arg2;
			else if (s[i]=='/') wynik=arg1/arg2;
			else if (s[i]=='^'){
				wynik = 1;
				for (int i = 0; i < arg2; i++)
				{
					wynik *= arg1;
				}
			}
			stos.push(wynik);
		}
	wynik=stos.top();
	stos.pop();
	return wynik;	
}
 
int main()
{
	string s;
	cout<<"Podaj wyrazenie w ONP: "; cin>>s;
 	cout<<"Wartosc: "<<Oblicz(s);
	return 0;              
}
