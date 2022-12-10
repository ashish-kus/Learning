#include<iostream>
using namespace std;

int RecursiveFactorial(int num)
	{
		if(num<=1)
			return 1;
		else
			return num * RecursiveFactorial(num-1);

	}

int Factorial(int num)
	{
		int facto=1;

		if(num <=1)
			return facto;
		else
		{
			for(int i=1; i<=num; i++)
			{
				facto=facto*i;
			}
			return facto;
		}
	}	
int main(){
	int num, Rfacto, Nfacto;
	cout<<" Enter a number: ";
	cin>>num;

	Rfacto = RecursiveFactorial(num);
	Nfacto = Factorial(num);

	cout<<" Factorial: "<<Rfacto<<"  ( using recurtion)"<<endl;
	cout<<" FActorial: "<<Nfacto<<"  ( Normal function)";
return 0;
}

