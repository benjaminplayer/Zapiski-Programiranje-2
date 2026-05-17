#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int val;
    struct _node* next;
} node;

node* selSort(node* a)
{
    if (a->next == NULL) return a;
    a->next = selSort(a->next);
    return a;
}

int findMin(int* a, const int n)
{
    if (n == 1) return 0;
    int m = findMin(&a[1],n-1);
    if (a[0] < a[m]) return 0;
    return m;
}

node* minToHead(node* a)
{
    if (a == NULL) return a;
    node* new_tail = minToHead(a->next);
    if ((new_tail == NULL) || (a->val < new_tail->val))
    {
        a->next = new_tail;
        return a;
    }
    a->next = new_tail->next;
    new_tail->next = a;
    return new_tail;

}

void selSortRecursively(int* a, const int n)
{
    if (n == 1) return;
    const int imin = findMin(a,n);
    const int t = a[imin];
    a[imin] = a[0];
    a[0] = t;
    selSortRecursively(&a[1], n-1);
}

void selectionSort(int* a, int n)
{
    for (int i = 0; i < n;i++) // new el, repeat
    {
        int imin = i; // najdi min
        for (int j = i+1; j <= n-1; j++)
            if (a[j] < a[imin])
                imin = j;
        const int t = a[i]; // zamenjaj cur za min
        a[i] = a[imin];
        a[imin] = t;
    }
}

int main(int argc, char *argv[])
{

}
