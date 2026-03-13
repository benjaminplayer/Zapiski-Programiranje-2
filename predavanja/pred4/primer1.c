#include <stdio.h>
int sqr(int n)
{
    int s = n*n;
    return s;
}

int main(int argc, char *argv[])
{
    int a = 5;
    int b = sqr(a);
    printf("%d\n",b);
    return 0;
}

