#include<iostream>
using namespace std;

int BinarySearch(int array[],int size, int key){
	int start=0;
	int end=size;
	while(start<=end){
		int mid=(start+end)/2;

		if(array[mid]==key){
			return mid;
		}
		else if(array[mid]>key){
			end=mid-1;
		}
		else{
			start=mid+1;
		}
	}
	return -1;
}
int main(){
	int size, key, position = -1;
	cout<<"SIZE of array";
	cin>>size;
	int array[size];

	for(int i=0; i<size; i++){	
		cout<<"element at "<<i<<":";
		cin>>array[i];
	}

	cout<<"Key: ";
	cin>>key;
	position=BinarySearch(array,size-1,key);



	if(position != -1){
		cout<<"position :"<<position<<endl;
	}
	else{
		cout<<"not found";
	}
return 0;
}
