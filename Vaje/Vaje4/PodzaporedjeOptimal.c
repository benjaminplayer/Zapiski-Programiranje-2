#include <stdio.h>
#include <limits.h>
int main(int argc, char *argv[])
{
    int n;
    scanf("%d",&n);

    int sum = 0;
    int maxSum = INT_MIN;

    // tekoca vsota od zacetka zaporedja oz mesta, kjer sum pade pod 0

    for (int i = 0; i < n; i++)
    {
        int read;
        scanf("%d",&read);
        sum += read;
        if (sum > maxSum)
            maxSum = sum;

        // dedovanje dolgov ni cool
        if (sum < 0)
            sum = 0;

    }

    printf("%d\n", maxSum);
    return 0;
}
