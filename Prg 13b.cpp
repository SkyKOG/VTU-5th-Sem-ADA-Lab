/**
Lab Program 13b
Warshall's Transitive Closure - Dynamic Programming
Author SkyKOG
*/

#include<iostream>
#include<conio.h>

#define MAX 50

using namespace std;

class Warshalls
{
	int a[MAX][MAX],n;
	
	public:
		void costmat();
		void wtc();
		void display();
};

void Warshalls::costmat()
{
	cout<<"Enter Number of Nodes : ";
	cin>>n;

	cout<<"\nEnter The Cost Adjacency Matrix (0-No Edge 1-Edge)\n\n";
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			cin>>a[i][j];
}

void Warshalls::wtc()
{
	for(int k = 1 ;k <= n ; k++)
		for (int i = 1 ; i <= n ; i++)
			for (int j = 1 ; j <= n ; j++)
				if(a[i][k] && a[k][j])
					a[i][j]=1;
}

void Warshalls::display()
{
	int i;

	cout<<"\nSolution for Warshall's Transitive Closure :\n\n";
	for (i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
			cout<<a[i][j]<<" ";
		cout<<"\n";
	}
}

void main()
{
	Warshalls obj;

	obj.costmat();
	obj.wtc();
	obj.display();

	getch();
}