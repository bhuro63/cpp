#include <iostream.h>
#include <conio.h>

void main()
{
    int i, j;
    int a = 0, b = 1, c;

    clrscr();

    for(i = 1; i <= 4; i++)
    {
        for(j = 1; j <= 4 - i; j++)
            cout << "  ";

        for(j = 1; j <= i; j++)
        {
            cout << a << "   ";

            c = a + b;
            a = b;
            b = c;
        }

        cout << endl;
    }

    getch();
}
