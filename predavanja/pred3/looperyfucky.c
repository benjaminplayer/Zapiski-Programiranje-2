#include <stdio.h>

int main(int argc, char const *argv[])
{
    float x = 1.0, y = 1.0;
    while ((x + y) + y == x + (y + y))
        y /= 2.0;

    printf("%30.25f %30.25f\n",x, y);
    printf("%30.25f %30.25f\n",(x + y) + y, x + (y + y));
    return 0;
}
