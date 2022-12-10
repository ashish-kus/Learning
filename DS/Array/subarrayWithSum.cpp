#include<iostream>
using namespace std;

int main(){
	int size, s;
	cout<<" Enter the size of array: ";
	cin>>size;
	int arr[size];

	cout<<" Sun: ";
	cin>>s;

	for(int i=0; i<size; i++)
	{
		cin>>arr[i];
	}
	
	int i = 0,j=0, start = -1, end = -1, sum=0, sub=0;
	
	while(j<size &&  sum<=s)
	{
		sum = sum + arr[j];
	
		if(sum == s)
		{
			start=0;
			end=j;
			cout<<" Start = "<<start<<endl;
			cout<<" End = "<<end;
			return 0;
		}
		j++;
	}

	for(i=0 ;i<j; i++)
	{
		if(sum == s)
		{
			cout<<" Start :"<<i<<endl;
			cout<<" End   :"<<j<<endl;
		}
		
		sub= sub + arr[i];
		sum= sum-sub;
	}

	return 0;
}
