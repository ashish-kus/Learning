#include<iostream>
using namespace std;

int main(){
	int height;
	cout<<" Height: ";
	cin>>height;
	
	int var=1;
	for(int i=1;i<=height;i++)

	{
		for(int j=0; j<i ; j++)
		{

		cout<<" "<<var<<" ";
			var++;
		}

		cout<<endl;
	}
	return 0;
}
