#include<iostream>
using namespace std;

int main(){

	int num;
	cout<<" Age: ";
	cin>>num;

	for(int i=1; i<=num; i++)
	{
		for(int j=0; j<i; j++)
		{ 
			cout<<" * ";
		}

		for(int k=0; k<(2*num-2*i);k++)
		{
			cout<<"   ";
		}
		for(int l=0; l<i; l++)
		{
			cout<<" * ";
		}
	cout<<endl;
	}
	   for(int i=num; i>=1; i--)
        {
                for(int j=0; j<i; j++)
                { 
                        cout<<" * ";
                }

                for(int k=0; k<(2*num-2*i);k++)
                {
                        cout<<"   ";
                }
                for(int l=0; l<i; l++)
                {
                        cout<<" * ";
                }
        cout<<endl;
        }


	return 1;
}
