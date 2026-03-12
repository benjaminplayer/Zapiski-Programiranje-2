#include <stdio.h>
#include <stdbool.h>
long long invert(long n)
{
    long long new = 0;
    while (n > 0)
    {
        new = new * 10 + n % 10;
        n /= 10;
    }

    return new;
}

bool isLyncer(long long n, int k)
{
    for (int i = 0; i < k; i++)
    {
        n += invert(n);
        if (invert(n) == n)
            return false;
        if (n > 1e17) return true;
    }

    return true;

}

int main(int argc, char *argv[])
{
    int k, a, b;
    scanf("%d %d %d", &k,&a, &b);
//    printf("%d\n", invert(a));
    int count = 0;
    for (int i = a; i <= b; i++)
    {
        if (isLyncer(i,k)) count++;
    }

    printf("%d\n", count);


    return 0;
}
