#include<stdio.h>
#include<conio.h>
#include<iostream.h>
class A {
	int a,b;
	public:
	friend void get (A&a1);
	friend void put (A&a1);

	void show()
	{
	cout<<"show";
	}
};
void get(A&a1)
{
	    int A::*pa=&A::a;
	    int A::*pb=&A::b;
	    A*a1;
	    p1=&a1;
	    cout<<"eneter two number";
	    cin>>p1->*pa>>a1.*pb;
}
void put(A&a1)
{
	A*p1;
	p1=&a1;
	cout<<"\n a="<<a1.a<<"\t b="<<p->b;
}
void main()
{
	A a1;
	clrscr();
	get(a1);
	put(a1);
	void (A::*pf)()=&A::show;
	(a1.*pf)();
	getch();
}
