#include<iostream.h>
#include<conio.h>
class A
{
	static int a;
	public:
	A()
	{
		cout<<"\n object ctreated-"<<++a;
	}
	~A()
	{
		cout<<"\n object destoyed-"<<a--;
	}
};
int A :: a;

void main()
{
	clrscr();
	A a1,a2;
	{
	A a3;
	}
	A a4;
	{
	A a5;
	}
	A a6;
	getch();
}


				     -

