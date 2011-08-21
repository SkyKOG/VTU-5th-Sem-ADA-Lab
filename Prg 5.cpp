/**
Lab Program 5
1/0 Knapsack - Dynamic Programming
Author SkyKOG
*/

#include <iostream>
#include <conio.h>

using namespace std;

int w[10],p[10],n,m;

int knap(int i,int j);
int max(int a,int b);

void main()
{
	int i;
	
	cout<<"Enter Number of Objects : ";
	cin>>n;
	
	cout<<"\nEnter Weights of Objects : ";
	for(i=1;i<=n;i++)
		cin>>w[i];

	cout<<"Enter Profits of Objects : ";
	for(i=1;i<=n;i++)
		cin>>p[i];

	cout<<"\nEnter Knapsack Capacity : ";
	cin>>m;

	int max=knap(n,m);
	
	cout<<"\n\nThe Optimal Solution is "<<max;
	
	getch();
}

int max(int a,int b)
{
	return a>b?a:b;
}

int knap(int i,int j)
{
	if(i==0||j==0)
		return 0;
	if(w[i]>j)
		return knap(i-1,j);
	return
		max(knap(i-1,j),knap(i-1,j-w[i])+p[i]);
}