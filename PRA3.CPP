#include<iostream.h>
#include<conio.h>

void main()
{
    char name[50];
    int i;

    clrscr();

    cout<<"Enter Name: ";
    cin>>name;

    for(i=0; name[i]!='\0'; i++)
        cout<<name[i]<<" ";

    cout<<endl;

    for(i=0; name[i]!='\0'; i++)
        cout<<"* ";

    cout<<endl;

    for(i=0; name[i]!='\0'; i++)
        cout<<name[i]<<" ";

    getch();
}