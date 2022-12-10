#include<iostream>
using namespace std;

int main(){
	int num;
	cout<<" Number : ";
	cin>>num;
//  Input taken

	// for rows
	for(int i=1; i<=num; i++){
		for(int j=1; j<=num;j++)
		{
			(j>=i)?(cout<<" "):(cout<<i);

		}
	cout<<endl;

	}



	return 0;

}
