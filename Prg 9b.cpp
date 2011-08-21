/**
Lab Program 9b
DFS Connected - Decrease And Conquer
Author SkyKOG
*/

#include <iostream>
#include <conio.h>

#define MAX 10

using namespace std;

class DFS {

	int i,j,source,visited[MAX],n,a[MAX][MAX],count;

	public:
		void input();
		void dfsconn(int,int a[MAX][MAX],int);
		void diplay();
};

void main()
{
	DFS obj;
	
	obj.input();
	obj.diplay();

	getch();
}

void DFS::input()
{
	cout<<"Enter Number of Nodes : ";
	cin>>n;

	cout<<"\nEnter Matrix : \n\n";
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			cin>>a[i][j];

	cout<<"\nEnter Source : ";
	cin>>source;

	for(i=1;i<=n;i++)
		visited[i]=0;

	dfsconn(n,a,source);
}

void DFS::dfsconn(int n,int a[MAX][MAX],int source)
{
	visited[source]=1;

	for(i=1;i<=n;i++)
		if(a[source][i] && !visited[i])
			dfsconn(n,a,i);
}

void DFS::diplay()
{
	count=0;
	
	for(i=1;i<=n;i++)
		if(visited[i])
			count++;

	if(count==n)
		cout<<"\nConnected Graph\n";
	else
		cout<<"\nDisconnected Graph\n";
}