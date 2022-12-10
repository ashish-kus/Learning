#include<iostream>
using namespace std;

int main(){
	int size;
	cout<<"enter the size of the array: ";
	cin>>size;
	int arr[size];

	for(int i=0; i<size; i++)
	{
		cin>>arr[i];
		for(int j=0; j<i;j++)
		{
			if(arr[i]==arr[j])
			{
				cout<<" First repeated element is at  "<<j;
				return 0;
		
			}	
		}
	}




		return 0;
}

