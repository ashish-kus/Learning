#include<iostream>
#include<climits>
using namespace std;
void swap(int *a, int *b){
	int temp= *a;
	*a=*b;
	*b=temp;
}


int main(){
	int size,min;
	cout<<" Enter the size of list: ";
	cin>>size;

	int arr[size];
	cout<<" Enter thr elements of list:"<<endl;

	for(int i=0; i<size; i++){
		cin>>arr[i];
	}

	for(int j=0; j<size-1; j++)
	{
		for(int k=j+1; k<size;k++)
		{
			if(arr[k]<arr[j])
				swap(&arr[k],&arr[j]);
		}		
	}

	for(int l=0 ; l<size; l++){
		cout<<" " <<arr[l];
	}




	return 0;
}

