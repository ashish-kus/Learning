#include<iostream>
using namespace std;

int main(){
	int num,var=1;
	cout<<"HEIIGHT: ";
	cin>>num;

	for(int i=1; i<=num;i++)
	{
		for(int j=0; j<i;j++)
		{
			if(var%2==0){cout<<" 0 ";}
			else{cout<<" 1 ";}
			var++;
		}
		cout<<endl;
	}
	return 0;
}

