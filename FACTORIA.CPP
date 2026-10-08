#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<math.h>

int factorial(int x);
void main()
{
	int a,b;
	clrscr();
	cout<<"enter your number=>";
	cin>>a;
	b=factorial(a);
	cout<<b;
}
int factorial(int x)
{
	 int r=1;

	 if(x==1)
	 return 1;
 else
	 r=x*factorial(x-1);
	 return r;
 }