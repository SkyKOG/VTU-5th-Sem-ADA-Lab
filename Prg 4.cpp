/**
Lab Program 4
Selection Sort
Author SkyKOG
*/

#include <iostream>
#include <conio.h>
#include <time.h>

#define MAX 10

using namespace std;

void selsort(int [],int);

void main()
{
    int i,n,a[MAX];
	clock_t start,end;

	cout<<"Enter Num of Elements : ";
	cin>>n;

	cout<<"\nEnter Elements : ";
	for(i = 0 ; i < n ; i++)
		cin>>a[i];
	
	start=clock();
    selsort(a, n);
	end=clock();

	cout<<"\nThe Sorted Elements Are : ";
    for(i = 0 ; i < n ; i++)  
		cout<<a[i]<<" ";
	
	cout<<"\n\nTime Taken : "<<(end-start)/(double)CLOCKS_PER_SEC;
	getch();
}

void selsort(int a[],int n)
{
	for(int i = 0 ; i < n-1 ; i++)
	{
		for(int j = i+1 ; j < n ; j++)
		{
			if(a[i] > a[j])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
