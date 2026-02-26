//
// Created by FireBlazeTSETSR on 24/02/2026.
//
#include<stdio.h>

int readInt() {
    char ch;
    int no = 0;
    while ((ch = getchar()) != '\n')
    {
        if (ch >= '0' && ch <= '9')
            no = no * 10 +  ch - '0';
        else break;
    }

    return no;
}

int main()
{
    int n = getchar() - '0', no = 0, prev = -1, out = 1;
    getchar(); // read a space after the first input;

    for (int i = 0; i < n; i++)
    {
        no = readInt();
        if (prev != -1 && no != prev)
        {
            out = 0;
            break;
        }
        prev = no;
        no = 0;
    }

    putchar(out+'0');

    return 0;
}