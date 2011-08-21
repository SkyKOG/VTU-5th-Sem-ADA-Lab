/**
Lab Program 3
Merge Sort
Author SkyKOG
*/

#include <iostream>
#include <conio.h>
#include <time.h>

#define MAX 10

using namespace std;

void msort(int a[],int low,int high);
void merge(int a[],int low,int mid,int high);

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
	msort(a,0,n-1);
	end=clock();

	cout<<"\nThe Sorted Elements Are : ";
    for(i = 0 ; i < n ; i++)  
		cout<<a[i]<<" ";
	
	cout<<"\n\nTime Taken : "<<(end-start)/(double)CLOCKS_PER_SEC;
	getch();
}

void merge(int a[],int low,int mid,int high)
{
	int i=low;   
	int j=mid+1;        
	int k=low;              
	int temp[MAX];       

	while(i<=mid && j<=high)
	{
		if(a[i]<a[j])
		{
			temp[k]=a[i]; 					
			i++;k++;      
		}
		else
		{
			temp[k]=a[j];						  
			j++;k++;     
		}
	}

	while(i<=mid) 						
		temp[k++]=a[i++];

	while(j<=high) 					  
		temp[k++]=a[j++];

	for(i=low;i<=high;i++)
		a[i]=temp[i];
}

void msort(int a[],int low,int high)
{
	int mid;

	if(low<high)
	{
		mid=(low+high)/2; 
		msort(a,low,mid);
		msort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}