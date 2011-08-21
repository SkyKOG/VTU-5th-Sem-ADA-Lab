/**
Lab Program 9a
BFS Traversal - Decrease And Conquer
Author SkyKOG
*/

#include <iostream>
#include <conio.h>

#define MAX 10

using namespace std;

class BFS {

	int visited[MAX],n,a[MAX][MAX],i,j,source;
	
	public:
		void input();
		void bfstraverse();
		void display();
};

void main()
{
	BFS obj;

	obj.input();
	obj.bfstraverse();
	obj.display();

	getch();
}

void BFS::input()
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
}
void BFS::bfstraverse()
{
	int i,queue[MAX],u,front=1,rear=1;	

	queue[rear]=source;

	while(front<=rear)
	{
		u=queue[front++];
		for(i=1;i<=n;i++)
		{
			if(a[u][i] && !visited[i])
			{
				queue[++rear]=i;
				visited[i]=1;
			}
		}
	}
}

void BFS::display()
{
	for(i=1;i<=n;i++)
	{
		if(visited[i])
			cout<<"\nThe node is reachable "<<i<<"\n";
		else
			cout<<"\nNot Reachable "<<i<<"\n";
	}
}
