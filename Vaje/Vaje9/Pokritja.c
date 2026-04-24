#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* readIntoArray(int n,int* sum)
{
    int s = 0;
    int* arr = (int*)calloc(n,sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
        s += arr[i];
    }
    *sum = s;
    return arr;
}

int calcSum(int n, int* arr)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}

void printSet(const int n, const int* set, const bool* used)
{
    for (int i = 0; i < n - 1; i++)
        if (used[i])
            printf("%d, ",set[i]);
}

void iterate(int n, int* set, int sePotrebno, int idx, bool* used)
{
    if (sePotrebno < 0) return;
    if (sePotrebno == 0)
    {
        printSet(n, set, used);
        return;
    }
    for (int i = idx; i < n; i++)
    {
        if (set[i] <= sePotrebno)
        {
            used[idx] = true;
            iterate(n,set,sePotrebno - set[idx], idx+1,used);
            used[idx] = false;
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int sum;
    int* arr = readIntoArray(n,&sum);
    bool* used = (bool*)calloc(n,sizeof(bool));

    if (used != NULL && arr != NULL)
        iterate(n,arr,sum/2,1,used);

    free(arr);
    free(used);
    return 0;
}