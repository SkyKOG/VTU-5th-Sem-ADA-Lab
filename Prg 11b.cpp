/**
Lab Program 11b
Binomial Coefficient - Dynamic Programming
Author SkyKOG
*/

#include <iostream>
#include <conio.h>

#define MAX 10

using namespace std;

int bincoeff(int,int);

void main()
{
	int n,k;

	cout<<"Enter Value For n & k (n>k) : ";
	cin>>n>>k;

	int res=bincoeff(n,k);

	cout<<"\nThe Result is : "<<res;

	getch();
}

int bincoeff(int n,int k)
{
	int c[MAX][MAX];

	for(int i = 0 ; i <= n ; i++)
	{
		for(int j = 0 ; j <= k ; j++)
		{
			if(!j || i == j)
				c[i][j]=1;
			else
				c[i][j]=c[i-1][j-1]+c[i-1][j];
		}
	}
	return c[n][k];
}