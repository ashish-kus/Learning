#include<iostream>
using namespace std;

int main(){
	int key,position,size;
	cout<<"Size: ";
	cin>>size;
	cout<<"Enter "<<size <<" Numbers: "<<endl;
	bool status=0;
	string result;

	int arr[size];

	for(int i=0;i<size; i++){
		cin>>arr[i];
	}

	cout<<" Enter the key you want: ";
	cin>>key;
	
	for(int j=0; j<size; j++){
		if(arr[j] == key)
		{
			cout<<" Position of Key is : "<<j<<endl;
			status=1;
		}
	}

	if(status==0)
		cout<<" Element not found"<<endl;
	else
		cout<<" Found" <<endl;
	return 0;
}
