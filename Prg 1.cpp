/**
Lab Program 1a
Recursive Binary Search
*/

#include <iostream>
#include <conio.h>
#include <time.h>

#define MAX 10

using namespace std;

int binary(int key,int a[],int low,int high)
{
	if(low>high)
		return -1;
	int mid=(low+high)/2;
	if(key<a[mid])
		return binary(key,a,low,mid-1);
	else if(key>a[mid])
		return binary(key,a,mid+1,high);
	return mid;
}


void main()
{
	int n,a[MAX],i,key;
	time_t end,start;
	
	cout<<"Enter Array Size : ";
	cin>>n;
	
	cout<<"\nNumbers Have Been AutoGen As Follows : \n";
	for (i=0;i<n;i++)
	{
		a[i]=i;
		cout<<"\nElemnt "<<i<<"is "<<a[i];
	}

	cout<<"\n\nEnter Element To Search : ";
	cin>>key;

	int pos;

	time(&start);
	pos=binary(key,a,0,n-1);
	time(&end);

	cout<<"\nTime Taken : "<<difftime(end,start)<<" Units";

	if(pos==-1)
		cout<<"\n\nUnsuccessful search\n";
	else
		cout<<"\n\nKey found at Position : "<<pos+1;

	getch();
}