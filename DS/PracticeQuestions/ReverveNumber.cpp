#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
	int num,i = 0, reverce=0, reminder;
	cout<<"Enter a Number : ";
	cin>>num;

	while(num!=0){
		reminder=num%10;
		reverce=reverce*10+reminder;
		num=num/10;
		}
	cout<<"Your reverced Number is : "<<reverce;

	return 0;
}
