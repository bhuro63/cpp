#include<stdio.h>
#include<conio.h>
#include<iostream.h>
void main()
{
	   int last,binary,decimal=0,base=1;
	   clrscr();
	    cout<<"enter binary number=>";
	    cin>>binary;
	    while(binary>0)
	   {
		last=binary%10;
		decimal=decimal+(last*base);
		base=base*2;
		binary=binary/10;
	   }
	   cout<<"decimal number:"<<decimal;
	   getch();

}