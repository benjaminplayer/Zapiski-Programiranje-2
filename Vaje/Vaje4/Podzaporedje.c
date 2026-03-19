#include <stdio.h>
#include <stdlib.h>

#define MAX_DOLZINA 1000000

int arr[MAX_DOLZINA];

int main(int argc, char *argv[])
{
    int n, read;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &read);
        arr[i] = read;
    }
    int sum, maxSum = 0;
    int start_i = 0, end_i = 0;

    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum > maxSum)
                maxSum = sum;
        }
    }

    printf("%d, %d, %d\n",start_i, end_i - start_i ,maxSum);
    return 0;

}