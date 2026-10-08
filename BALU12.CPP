#include<iostream.h>
#include<conio.h>
class A
{
	int a;
	public:
	void get()
	{
		cout<<"enter a=>";
		cin>>a;
	}
	void put()
	{
		cout<<"\n a="<<a;
	}
	void change() const
	{
	cout<<"\n can not change";
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

