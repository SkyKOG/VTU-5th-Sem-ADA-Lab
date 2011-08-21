/**
Lab Program 13a
Floyd's All Pairs - Dynamic Programming
Author SkyKOG
*/

#include<iostream>
#include<conio.h>

#define MAX 50

using namespace std;

class Floyds
{
	int a[MAX][MAX],n;
	
	public:
		void costmat();
		void floydy();
		int min(int,int);
		void display();
};

void Floyds::costmat()
{
	cout<<"Enter Number of Nodes : ";
	cin>>n;

	cout<<"\nEnter The Cost Adjacency Matrix (0-Self Loop 999-No Edge)\n\n";
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			cin>>a[i][j];
}

void Floyds::floydy()
{
	for(int k = 1 ;k <= n ; k++)
		for (int i = 1 ; i <= n ; i++)
			for (int j = 1 ; j <= n ; j++)
				a[i][j] = min(a[i][j],(a[i][k] + a[k][j]));
}

void Floyds::display()
{
	int i;

	cout<<"\nSolution for Floyd's All Pairs Shortest Path :\n\n";
	for (i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
			cout<<a[i][j]<<" ";
		cout<<"\n";
	}
}

int Floyds::min(int a,int b)
{
	return (a<b)?a:b;
}

void main()
{
	Floyds obj;

	obj.costmat();
	obj.floydy();
	obj.display();

	getch();
}