/**
Lab Program 8
Kruskal's Algorithm - Greedy
Author SkyKOG
*/

#include <iostream>
#include <conio.h>

#define MAX 20

using namespace std;

int parent[MAX],cost[MAX][MAX],t[MAX][2];

void kruskal(int);
int find(int);
void unite(int,int);

void main()
{
	int i,j,n;

	cout<<"Enter Number of vertices : ";
	cin>>n;

	for(i=1;i<=n;i++)
		parent[i]=0;

	cout<<"\nEnter Cost Matrix : \n\n";
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			cin>>cost[i][j];
	}
	
	kruskal(n);

	getch();
}

int find(int v)
{
	while(parent[v])
		v=parent[v];
	return v;
}

void unite(int i,int j)
{
	parent[j]=i;
}

void kruskal(int n)
{
	int i,j,k,u,v,mincost,res1,res2,sum=0;

	for(k=1;k<=n;k++)
	{
		mincost=999;
		for(i=1;i<=n-1;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(i==j)continue;
				if(cost[i][j]<mincost)
				{
					u=find(i);
					v=find(j);
					if(u!=v)
					{
						res1=i;
						res2=j;
						mincost=cost[i][j];
					}
				}
			}
		}
		unite(res1,find(res2));
		t[k][1]=res1;
		t[k][2]=res2;
		sum=sum+mincost;
	}
	cout<<"\nCost : "<<sum;
	cout<<"\n\nEdges : \n\n";
	for(i=1;i<n;i++)
		cout<<t[i][1]<<" -> "<<t[i][2]<<"\n";
}