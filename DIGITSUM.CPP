#include<stdio.h>
#include<iostream.h>
#include<conio.h>
void main()
{
	 int num,sum=0;
	 clrscr();
	 cout<<"enter your a value=>";
	 cin>>num;
	 while(num!=0)
	 {
		sum=sum+(num%10);
		num=num/10;
	 }
	 cout<<"sum of digits=>"<<sum;
}