			#include<iostream.h>
#include<conio.h>
#include<string.h>
class string
{
	int len;
	char *nm;
	public:
    string()
	{
		cout<<"\n default dynamic constructor:";
		len=0;
		nm=new char[len+1];
	}
	string (char*s)
	{
		cout<<"\n parameterized dynamic constructor:";
		//len=strler(s);
		nm=new char[len+1];
		strcpy(nm,s);
	}
	void put()
	{
		cout<<"\n name="<<nm;
	}
	friend string concat(string s1,string s2);
};
string concat(string s1,string,s2);
{
	string s3;
	s3.len=s1.len+s2.len;
	s3.nm=new char[s3.len+1];
	strcpy(s3.nm,s1.nm);
void main()
{
	 







