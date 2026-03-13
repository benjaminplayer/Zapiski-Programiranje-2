#include <stdio.h>
#include <stdbool.h>

void readUntilSpace(void)
{
    while (getchar()!=' ');
}

int main(int argc, char *argv[])
{
    char c;
    bool first = true, firstZero = false;
    int len = 0;
    while ((c = getchar()) != '\n')
    {
        if (c >= '0' && c <= '9')
        {
            if (first)
                firstZero = c == '0';
            first = false;
            len++;
        }
        else if (c == ' ')
        {
            if (firstZero && len > 1) putchar('0');
            else putchar('1');
            len = 0;
            first = true;
        }
        else
        {
            putchar('0');
            len = 0;
            first = true;
            readUntilSpace();
        }
    }
    if (firstZero && len > 1) putchar('0');
    else putchar('1');
}
