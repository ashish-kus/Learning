#include<iostream>
using namespace std;

int main(){
	int num;
	cout<<" Height: ";
	cin>>num;

	for(int i=1; i<=num; i++)
	{
		for(int a=0; a<num-i;a++)
			{
				cout<<"   ";
			}
		for(int b=i;b>0;b--)
		{
//			cout<<"H"<<endl;
			cout<<" "<<b<<" ";
		}
		for(int c=2; c<=i; c++)
		{
			cout<<" "<<c<<" ";
		}
		cout<<endl;
	}


	return 0;
}
