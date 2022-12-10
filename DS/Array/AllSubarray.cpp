#include<iostream>
using namespace std;

int main(){

	int size;
	cout<<"enter a size";
	cin>>size;

	int arr[size];

	for(int i=0; i<size; i++){

		cin>>arr[i];
	}

	for(int i=0; i<size; i++){
		for(int j=i; j<size; j++){
			cout<<"  " <<arr[j];
		}
		cout<<endl;
	}

	return 0;
}
