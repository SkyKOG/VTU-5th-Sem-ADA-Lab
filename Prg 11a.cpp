/**
Lab Program 11a
Horspool String Matching - Space n Time 
Author SkyKOG
*/

#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

class HP {
	
	char mainstr[50],pattern[50];
	int mlen,plen,table[256];

	public:
		void shftable();
		int matcher();
		void input();
};

void main()
{
	HP obj;

	obj.input();
	int pos=obj.matcher();

	if(pos==-1)
		cout<<"\nPattern Not Found";
	else
		cout<<"\nPattern Found At Position : "<<pos+1;

	getch();
}

void HP::input()
{
	cout<<"Enter Main String : ";
	cin.getline(mainstr,50);

	cout<<"\nEnter Pattern String : ";
	cin.getline(pattern,50);
}

void HP::shftable()
{
	plen=strlen(pattern);

	for(int i=0;i<128;i++)
		table[i]=plen;

	for(int i=0;i<plen-1;i++)
		table[pattern[i]]=plen-i-1;
}

int HP::matcher()
{
	int i,k;

	shftable();

	mlen=strlen(mainstr);
	plen=strlen(pattern);
	i=plen-1;

	while(i<mlen)
	{
		k=0;
		while(k<plen && mainstr[i-k]==pattern[plen-1-k])
			k++;
		if(k==plen)
			return i-plen+1;
		i=i+table[mainstr[i]];
	}
	return -1;
}