#include <iostream.h>
#include <conio.h>

void main()
{
    int i, j;

    clrscr();

    for(i = 1; i <= 4; i++)
    {
        for(j = 1; j <= 8 - i; j++)
	    cout <<"  ";

        for(j = i; j >= 1; j--)
	    cout << j % 2 <<"    ";

        cout << endl;
    }

    getch();
}
