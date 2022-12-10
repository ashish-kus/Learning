#include<iostream>
#include<climits>
using namespace std;

int main(){
	int till,size,max=INT_MIN;
	cout<<"Enter thr size of list"<<endl;
	cin>>size;
	int arr[size];
	
	cout<<"Enter the elemets of the list"<<endl;
	for(int i=0; i<size; i++){

		cin>>arr[i];

	}
	cout<<"Max Till: ";
	cin>>max;

	for(int j=max; j>=0; j--)
	{
		if(arr[j]>max)
			max=arr[j];
	}
	 cout<<endl<<max;

	return 0;
}

