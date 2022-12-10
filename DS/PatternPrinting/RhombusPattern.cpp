#include<iostream>
using namespace std;

int main(){

	int num;
	cout<<" Number :";
	cin>>num;

	for(int i=num; i>0; i--)
	{
		for(int j=1;j<i;j++)
		{ 
			cout<<" ";
		}
		for(int k=0; k<num; k++)
		{
			cout<<" * ";
		}
		cout<<endl;
	}

	return 0;
}
