#include<iostream>
using namespace std;
int main(){
	int num,var;
	cout<<" NUMBER : ";
	cin>>num;
	var=1;

	for(int i=1; i<=num; i++)
	{
		if(i%2==0){var=0;}
		else{var=1;}

		for(int j=0; j<i;j++)
		{
			cout<<var<<" ";
			var=(var==0)?1:0;
		}
		
		cout<<endl;
	}
	return 0;
}
