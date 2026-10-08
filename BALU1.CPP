#include<stdio.h>
#include<conio.h>
#include<iostream.h>

inline int add(int a,int b)
{
	return(a+b);
}
void main()
{
	int a,b;
	clrscr();

	cout<<"enter a numbers=>";
	cin>>a;

	cout<<"enter b numbers=>";
	cin>>b;

	cout<<"\n sum="<<add (a,b);

	getch();
}