//
// Created by FireBlazeTSETSR on 24/02/2026.
//
#include <stdint.h>
#include<stdio.h>
int main()
{
    int n, read, max = INT32_MIN, second_max = max;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &read);
        if (read > max && read > second_max)
        {
            max = read;
        }
        else if (read < max && read > second_max) {
            second_max = read;
        }

        if (read == max) second_max = read;
    }

    printf("%d", second_max);

    return 0;
}