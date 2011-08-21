/**
Lab Program 6
Dijkstra Algorithm - Greedy
Author SkyKOG
*/

#include <iostream>
#include <conio.h>

#define MAX 50
#define INFINITY 999

using namespace std;

int n,dist[MAX][MAX],d[MAX]; 

void display();
void dijkstra(int);

void main()
{
	int i, j;
	
	cout<<"Enter Number of Edges : ";
	cin>>n;
	
	cout<<"\nEnter Cost Matrix 0-No Edge :  \n\n";
	for (i = 1; i <=n; ++i)
		for (j = 1; j <=n; ++j)
			cin>>dist[i][j];
	
	i=1;
	while(i<=n)
	{
		cout<<"\nSource is : "<<i<<"\n";
		dijkstra(i);
		display();
		getch();i++;
	}
}

void display() 
{
	cout<<"\n";
	for (int i = 1; i <= n; ++i)
		cout<<"\t"<<i;
	cout<<"\n";
	for (int i = 1; i <= n; ++i)
		cout<<"\t"<<d[i];	
	cout<<"\n";
}

void dijkstra(int s) 
{
	int i, k, mini;
	int visited[MAX];

	for (i = 1; i <= n; ++i) 
	{
		d[i] = INFINITY;
		visited[i] = 0;
	}

	d[s] = 0;

	for (k = 1; k <= n; ++k) 
	{
		mini = -1;
		for (i = 1; i <= n; ++i)
			if (!visited[i] && ((mini == -1) || (d[i] < d[mini])))
				mini = i;

		visited[mini] = 1;

		for (i = 1; i <= n; ++i)
			if (dist[mini][i])
				if (d[mini] + dist[mini][i] < d[i])
					d[i] = d[mini] + dist[mini][i];
	}
}