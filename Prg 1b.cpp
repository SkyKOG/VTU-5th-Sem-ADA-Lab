/**
Lab Program 1b
Recursive Linear Search
Author SkyKOG
*/

#include <iostream>
#include <conio.h>
#include <time.h>

#define MAX 10

using namespace std;

int linear(int a[],int key,int n)
{
	if(n<0)
		return -1;
	if(key==a[n])
		return n;
	return linear(a,key,n-1);
}

void main()
{
	int a[MAX],n,key,pos;
	time_t start,end;
	
	cout<<"Enter Number of Elements : ";
	cin>>n;

	cout<<"\nEnter Elemets : ";
	for(int i=0;i<n;i++)
		cin>>a[i];	

	cout<<"\nEnter Element To Search : ";
	cin>>key;

	time(&start);
	pos=linear(a,key,n);
	time(&end);

	cout<<"\nTime Taken : "<<difftime(end,start)<<" Units";

	if(pos==-1)
		cout<<"\n\nNot Found";
	else
		cout<<"\n\nElement Found At Position : "<<pos+1;

	getch();
}