#include <graphics.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\TC\\BGI");

    // Outer diamond
    line(200,100,150,150);
    line(150,150,200,300);
    line(200,300,250,150);
    line(250,150,300,100);
    line(300,100,200,100);

    // Middle line
    line(150,150,250,150);

    // Top facets
    line(200,100,175,150);
    line(200,100,210,150);
    line(250,100,230,150);
    line(250,100,250,150);

    getch();
    closegraph();
    return 0;
}