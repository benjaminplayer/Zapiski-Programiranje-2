#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 400

long** createArray(int const n)
{
    long** arr = (long**)calloc(n + 2,sizeof(long*));
    if (arr == NULL) exit(1);
    for (int i = 0; i < n; i++)
    {
        arr[i] = (long*)calloc(n + 2, sizeof(long));
        if (arr[i] == NULL) exit(1);
    }
    return arr;
}

void disposeArray(int const n, long** arr)
{
    for (int i = 0; i < n; i++)
        free(arr[i]);
    free(arr);
}

long partition_mem(int const sum, int const k, long** mem)
{
    if (sum < 0 || k <= 0) return 0;
    //if (mem != NULL && mem[sum][k] != 0) return mem[sum][k];
    if (sum == 0)
        return 1;
    if (mem[sum][k] > 0) return mem[sum][k];
    const long s = partition_mem(sum - k, k,mem) + partition_mem(sum, k - 1,mem);
    mem[sum][k] = s;
    return mem[sum][k];
}

long partition(int const sum, int const k)
{
    long** mem = createArray(MAX_SIZE);
    const long s = partition_mem(sum, k, mem);
    disposeArray(sum + 2, mem);
    return s;
}

void printArray(int const n, const int* arr)
{
    for (int i = 0; i < n - 1; i++)
        printf("%d + ",arr[i]);
    printf("%d\n",arr[n - 1]);
}

void vsota2(int const n, int const k, int* cleni, int const st_clenov)
{
    if (n < 0 || k <= 0) return;
    if (n == 0)
    {
        printArray(st_clenov, cleni);
        return;
    }
    cleni[st_clenov] = k;
    vsota2(n-k, k, cleni, st_clenov + 1);
    vsota2(n, k - 1, cleni, st_clenov);
}

void partition_out(int const n, int const k)
{
    int* cleni = (int*)malloc(n*sizeof(int));
    if (cleni == NULL) exit(1);
    vsota2(n, k, cleni, 0);
    free(cleni);
}

int main(int argc, char *argv[])
{
    int n, k;
    scanf("%d %d", &n, &k);
    // printf("%ld\n", partition(n, k));
    partition_out(n, k);
}
