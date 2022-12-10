#include<iostream>
using namespace std;

int main(){
	int Height;
	cout<<" what will be the hight os the Prymaid: ";
	cin>>Height;

	for(int i=1;i<=Height;i++)
	   {
		for(int j=0; j<i; j++){
	     		cout<<" "<<i;
		}	
		cout<<endl;	
	}

	return 0;
}
