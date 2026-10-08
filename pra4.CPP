#include <iostream.h>
#include <conio.h>

void main()
{
    int i, j, n = 6;

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n - i; j++)
            cout << " ";

        for(j = 1; j <= 2 * i - 1; j++)
        {
            if(i == n || j == 1 || j == 2 * i - 1)
                cout << "-";
            else
                cout << " ";
        }
        cout << endl;
    }

    getch();
}
