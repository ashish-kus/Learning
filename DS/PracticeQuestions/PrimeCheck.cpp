#include<iostream>
using namespace std;

int main(){
	int num;
	cout<<"number: ";
	cin>>num;

	if(num==0){
		cout<<" Its '0' and its not a prime number";
		return 0;
	}
	if(num==1){
		cout<<"It one and in modern mathamatics its not a prime number";
		return 0;
	}
	for(int i=2;i<num/2;i++){
		if(num%i==0){
			cout<<" Its not prime";
			return 0;
		}
	}
	cout<<"Prime no";
}
