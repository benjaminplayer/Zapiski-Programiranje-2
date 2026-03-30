#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,k;
    scanf("%d %d",&n, &k);

    int *seq = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d",&seq[i]);

    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
            if (seq[i] + seq[j] == k)
                count++;
    }
    printf("%d\n",count);
    free(seq);
}