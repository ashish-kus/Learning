#include<iostream>
using namespace std;

int main(){
	int num,var;
	cout<<"HEIIGHT: ";
	cin>>num;

	for(int i=num; i>0;i--)
	{
		var=1;
		for(int j=0; j<i;j++)
		{
			cout<<" "<<var<<" ";
			var++;
		}
		cout<<endl;
	}
	return 0;
}
