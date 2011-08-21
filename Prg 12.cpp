/**
Lab Program 12
Prim's Algorithm - Greedy
Author SkyKOG
*/

#include <iostream>
#include <conio.h>

using namespace std;

#define MAX 10

int prim(int [MAX][MAX],int,int);

void main()
{
	int a[MAX][MAX],source,n,i,j,m;

	cout<<"Enter Number of Vertex : ";
	cin>>n;

	cout<<"\nEnter Cost Matrix : \n\n";
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			cin>>a[i][j];
	}

	cout<<"\nEnter Source : ";
	cin>>source;
	cout<<"\n";

	m=prim(a,source,n);

	cout<<"\nCost : "<<m;

	getch();
}

int prim(int cost[MAX][MAX],int source,int n)
{
	int i,j,sum=0,visited[MAX],cmp[MAX],vertex[MAX],min,u,v;

	for(i=1;i<=n;i++)
	{
		vertex[i]=source;
		visited[i]=0;
		cmp[i]=cost[source][i];
	}
	visited[source]=1;	
	for(i=1;i<=n-1;i++)
	{
		min=999;
		for(j=1;j<=n;j++)
			if(!visited[j] && cmp[j]<min)
			{
				min=cmp[j];
				u=j;
			}
		visited[u]=1;
		sum=sum+cmp[u];
		cout<<vertex[u]<<" -> "<<u<<" Sum = "<<sum<<"\n";
		for(v=1;v<=n;v++)
			if(!visited[v] && cost[u][v]<cmp[v])
			{
				cmp[v]=cost[u][v];
				vertex[v]=u;
			}
	}
	return sum;
}