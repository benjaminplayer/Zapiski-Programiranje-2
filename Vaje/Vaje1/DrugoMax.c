//
// Created by FireBlazeTSETSR on 24/02/2026.
//
#include <stdint.h>
#include<stdio.h>

// read int je kinda useless, ker se mi ne da napisat func za
// outputat vecmestna st z putchar :)
int readInt()
{
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
    int n, max = INT32_MIN, second_max = max + 1;
    n = getchar() - '0';
    getchar(); //read space cene ne dela
    int prev = readInt();

    for (int i = 1; i < n; i++)
    {
        int cur = readInt();
        int localMax = (prev > cur)? prev : cur;
        if (localMax == max) second_max = max;
        else
        {
            if (localMax > max)
                max = localMax;
            if (prev < max && prev > second_max)
                second_max = prev;
            else if (cur < max && cur > second_max)
                second_max = cur;
        }

        prev = cur;
    }
    putchar(second_max + '0');
    //printf("%d", second_max);
    //printIntAsChars(second_max);
    return 0;
}