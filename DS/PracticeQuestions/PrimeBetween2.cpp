#include<iostream>
using namespace std;

bool isprime(int num){
		for(int i=2 ; i < num/2; i++)
		{
			if(num%i==0){
				return false;
			}
		}
	return true;
}

int main(){
	int start, end;
	cout<<" Enter two numbers "<<endl;

	cout<< " From : ";
	cin>>start;
	cout<<" To ";
	cin>>end;
	
	for(int i=start; i<=end; i++){
		if(isprime(i)){
			cout<<i<<endl;
		}
	}


	return 0;
}
