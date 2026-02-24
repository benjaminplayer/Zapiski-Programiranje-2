//
// Created by FireBlazeTSETSR on 24/02/2026.
//
#include<stdio.h>
int main()
{
    int n, no, prev = -1, out = 1;
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &no);
        if (prev != -1 && no != prev) {
            out = 0;
            break;
        }
        prev = no;
    }

    printf("%d", out);

    return 0;
}