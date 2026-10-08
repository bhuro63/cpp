#include<stdio.h>
#include<conio.h>
#include<iostream.h>
void main()
{
	   int n;
	   int rev=0;
	   int orn;
	   int last;
	   clrscr();
	    cout<<"enter number=>";
	    cin>>n;
	    orn=n;
	   while(n!=0)
	   {
		last=n%10;
		rev=(rev*10)+last;
		n=n/10;
	   }
	   if(orn==rev)
	   {
		cout<<"no is palimdrom";
	   }
	   else
	   {
		cout<<"no is not palimdrom";
	   }
	   getch();

}