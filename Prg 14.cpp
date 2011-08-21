/**
Lab Program 14
N-Queens - Backtracking
Author SkyKOG
*/

#include<iostream>
#include<math.h>
#include<stdlib.h>
#include <conio.h>

#define MAX 20

using namespace std;

void display(int [],int);
bool place(int [],int);
void nqueens(int );

void main()
{
	int n;
	cout<<"Enter The Number of Queens : ";
	cin>>n;
	cout<<"\nThe Solution To "<<n<<" Queens Problem :\n\n";
	nqueens(n);
	getch();
}

void nqueens(int n)
{
	int x[MAX];
	int k;

	x[0]=-1;
	k=0;

	while(k>=0)
	{
		x[k]=x[k]+1;
		while(x[k]<n&&!place(x,k))
			x[k]=x[k]+1;
		if(x[k]<n)
			if(k==n-1)
				display(x,n);
			else 
				x[++k]=-1;
		else
			k--;
	}
}

bool place(int x[],int k)
{
	int i;

	for(i=0;i<k;i++)
		if(x[i]==x[k]||abs(x[i]-x[k])==abs(i-k))
			return false;
	return true;
}

void display(int x[],int n)
{
	char chessb[MAX][MAX];
	int i,j;

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			chessb[i][j]='-';

	for(i=0;i<n;i++)
			chessb[i][x[i]]='Q';

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout<<chessb[i][j]<<"\t";
		cout<<"\n";
	}
	cout<<"\n";
}
