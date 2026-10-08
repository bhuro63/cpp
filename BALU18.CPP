#include<stdio.h>
#include<conio.h>
#include<iostream.h>

class A
{
	int a;
	public:
		void get()
		{
			cout << "\n Enter a value =>";
			cin >> a;
		}
		void put()
		{
			cout << "\n a = "<<a;
		}
		void change() const
		{
			//a++;
			cout << "\n Can not change";
		}
};

void main()
{
	A a1;
	clrscr();
	a1.get();
	a1.put();
	a1.change();
	getch();
}
idle lumer inc