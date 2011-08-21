/**
Lab Program 7
Quick Sort
Author SkyKOG
*/

#include <iostream>
#include <conio.h>
#include <time.h>

#define MAX 100000

using namespace std;

int split ( int a[ ], int lower, int upper );
void quicksort ( int a[ ], int lower, int upper );

void main( )
{
    int i,n,a[MAX];
	clock_t start,end;

	cout<<"Enter Num of Elements : ";
	cin>>n;

	cout<<"\nEnter Elements : ";
	for(i = 0 ; i < n ; i++)
		cin>>a[i];
					
	start=clock();
    quicksort(a,0,n-1);
	end=clock();

	cout<<"\nThe Sorted Elements Are : ";
    for(i = 0 ; i < n ; i++)  
		cout<<a[i]<<" ";
	
	cout<<"\n\nTime Taken : "<<(end-start)/(double)CLOCKS_PER_SEC;
	getch();
}

int split ( int a[ ], int lower, int upper )
{
	int p,q,i,t;

	p = lower + 1 ;
	q = upper ;
	i = a[lower] ;

	while ( q >= p )
	{
		while ( a[p] <= i )
			p++ ;

		while ( a[q] > i )
			q-- ;

		if ( q > p )
		{
			t = a[p] ;
			a[p] = a[q] ;
			a[q] = t ;
		}
	}

	t = a[lower] ;
	a[lower] = a[q] ;
	a[q] = t ;

	return q ;
}

void quicksort ( int a[ ], int lower, int upper )
{
	int i ;
	if ( upper > lower )
	{
		i = split ( a, lower, upper ) ;
		quicksort ( a, lower, i - 1 ) ;
		quicksort ( a, i + 1, upper ) ;
	}
}
