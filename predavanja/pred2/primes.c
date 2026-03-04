#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n)
{
    for(int i = 2; i < n; i++)
        if(n % i == 0) return false;
    return true;
}

int main()
{
    for (int i = 1; i <= 100; i++)
        if(isPrime(i)) printf("%d\n",i);
    printf("\n");
    return 0;
}