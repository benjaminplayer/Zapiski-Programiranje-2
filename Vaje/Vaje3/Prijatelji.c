#include <stdio.h>
#include <stdbool.h>

//vsota je enaka st

//pri st <= 6 se lahka zgodi da je b <= a
long calcSumOfDivisors(long n)
{
    long sum = 1;
    for (long i = 2; i < n; i++)
        if (n % i == 0) sum += i;
    return sum;
}

void printFriendly(long const n)
{
    long sumn = calcSumOfDivisors(n);
    long sum_i = calcSumOfDivisors(sumn);

    (sum_i == n)? printf("%ld",sumn) : printf("NIMA");
}

int main(int argc, char *argv[])
{
    long a;
    scanf("%ld", &a);
    printFriendly(a);

    return 0;

}
