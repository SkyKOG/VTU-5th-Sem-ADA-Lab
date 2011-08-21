/**
Lab Program 10
Generating Subsets - Decrease And Conquer
*/

#include <iostream>
#include <conio.h>
#include <cmath>

using namespace std;

void input();
void subset();
void display();

int set[100],sub[100],  sum, i, n, count, flag = 0;

void main()
{
	input();

	subset();

	if(!flag)
		cout<<"\nNo solutions found.";
	
	getch();
}
    
void input()
{    
	cout<<"Enter the Number of Elements : ";
    cin>>n;
	
    cout<<"\nEnter the Elements : ";
    for(i = 0; i < n; i++)
	cin>>set[i];

    cout<<"\nEnter the Sum d : ";
    cin>>sum;
}

void subset()
{
    int mask = pow(2.0,n);
    int total, j;
    
    for(i = 0; i < mask; i++)
    {
		count = total = 0;
	
		for(j = 0; j <= i; j++)
		{
			if(i & (1 << j))
			{
				total += set[j];
				sub[count] = set[j];
				count++;
			}
		}		
		if(total == sum)
			display();
	}
}

void display()
{
	flag = 1;
	cout<<"{";
	for(int j = 0; j < count; j++)
	cout<<" "<<sub[j];
	cout<<" }\n";
}