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
    const int n = getchar() - '0';
    int max = INT32_MIN, prevMax = max;
    getchar(); //read space cene ne dela

    for (int i = 0; i < n; i++)
    {
        const int read = readInt();
        if (read > max)
        {
            prevMax = max;
            max = read;
        }else if (read == max)
            prevMax = max;
        else if (read > prevMax)
            prevMax = read;

    }

    putchar(prevMax +'0');
    //putchar(second_max);


    //printf("%d", second_max);
    //printIntAsChars(second_max);
    return 0;
}