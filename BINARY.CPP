#include<stdio.h>
#include<conio.h>
#include<iostream.h>
void main()
{
	   int rev,binary=0,decimal,place=1;
	   clrscr();
	    cout<<"enter number=>";
	    cin>>decimal;
	    while(decimal>0)
	   {
		rev=decimal%2;
		binary=binary+(rev*place);
		place=place*10;
		decimal=decimal/2;
	   }
	   cout<<"binary number:"<<binary;
	   getch();

}