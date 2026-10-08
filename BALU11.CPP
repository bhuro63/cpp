#include<iostream.h>
#include<conio.h>

class A
{
    int a;

public:

    void get()
    {
        cout << "Enter a: ";
        cin >> a;
    }

    void put()
    {
        cout << "\na = " << a;
    }

    A add(A a1, A a2)
    {
        A a3;
        a3.a = a1.a + a2.a;
        return a3;
    }

    A add(A a2);
};

A A::add(A a2)
{
    A a3;
    a3.a = a + a2.a;
    return a3;
}

void main()
{
    A a1, a2, a3;

    clrscr();

    // First addition
    cout << "\nEnter value for a1:";
    a1.get();

    cout << "\nEnter value for a2:";
    a2.get();

    a3 = a1.add(a1, a2);

    cout << "\n\nFirst object:";
    a1.put();

    cout << "\nSecond object:";
    a2.put();

    cout << "\nAddition:";
    a3.put();

    // Second addition
    cout << "\n\nEnter value for a1:";
    a1.get();

    cout << "\nEnter value for a2:";
    a2.get();

    a3 = a1.add(a2);

    cout << "\n\nFirst object:";
    a1.put();

    cout << "\nSecond object:";
    a2.put();

    cout << "\nAddition:";
    a3.put();

    getch();
}