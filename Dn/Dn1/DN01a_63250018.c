#include<stdio.h>
#include<stdbool.h>

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

int main(int argc, char *argv[])
{
    char c;
    int n1 = 0, n2 = 0;
    bool neg = false;

    //first int
    while ((c = getchar()) != ' ')
        if (c == '-') neg = true;
        else n1 = n1 * 10 + c - '0';

    if (neg) n1 = -n1;
    neg = false;

    while ((c = getchar()) != '\n')
        if (c == '-') neg = true;
        else n2 = n2 * 10 + c - '0';

    if (neg) n2 = -n2;
    const int sum = n1 + n2;
    printNumber(sum);

    return 0;
}