//
// Created by FireBlazeTSETSR on 24/02/2026.
//
#include <stdint.h>
#include<stdio.h>

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

//TODO: Nrdi da dela
void printIntAsChars(int n)
{
    int tmp = n;
    while (tmp > 0)
    {
        tmp /= 10;
    }
}

int main()
{
    int n, max = INT32_MIN, second_max = max;
    n = getchar() - '0';
    getchar(); //read space
    //scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int read = readInt();
        if (read > max && read > second_max)
            max = read;
        else if (read < max && read > second_max)
            second_max = read;
        if (read == max) second_max = read;
    }
    printf("%d", second_max);
    //printIntAsChars(second_max);
    return 0;
}