#include <stdio.h>

void printNumber(int n)
{
    int num;
    if (n < 0)
    {
        num = -n;
        putchar('-');
    }
    else num = n;
    if (num / 10)
        printNumber(num / 10);
    putchar(num % 10 + '0');
}


int main()
{
    char c;
    int n = 0;
    while ((c = getchar()) != '\n')
        n = 2* n + (c - '0');

    printf("%d\n", n);

    int log = 0;
    while (n > 0)
    {
        n = n >> 1;
        log++;
    }

    printNumber(log);

    return 0;
}