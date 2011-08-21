/**
Lab Program 2
Heapsort
Author SkyKOG
*/

#include <iostream>
#include <conio.h>
#include <time.h>

#define MAX 10

using namespace std;

void heapsort(int [], int );

void main()
{
    int i,n,a[MAX];
	clock_t start,end;

	a[0]=0;
	
	cout<<"Enter Num of Elements : ";
	cin>>n;

	cout<<"\nEnter Elements : ";
	for(i=1;i<=n;i++)
		cin>>a[i];
		
	start=clock();
    heapsort(a, n);
	end=clock();

	cout<<"\nThe Sorted Elements Are : ";
    for(i = 1; i < n+1; i++)  
		cout<<a[i]<<" ";
	
	cout<<"\n\nTime Taken : "<<(end-start)/(double)CLOCKS_PER_SEC;
	getch();
}

void heapsort(int H[], int n)
{
    int i,k,v,j;
	
    for(i = n/2; i >= 1; i--)
    {
        k = i; v = H[k];
        bool heap = false;
        while(!heap && 2*k<=n)
        {
            j = 2*k;
            if(j < n)
                if(H[j] < H[j+1])
                    j = j+1;
            if(v >= H[j])
                heap = true;
            else
            {
                H[k] = H[j];
                k = j;
            }
        }
        H[k] = v;
    }
	for(int i=n-1;i>0;i--)
	{		
		int temp=H[n];
		H[n]=H[1];
		H[1]=temp;
		n--;
		heapsort(H,n);
		return;
	}
}