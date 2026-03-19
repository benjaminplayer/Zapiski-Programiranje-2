#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_DOLZINA_ZAP 1000000

int main()
{
    int n, read;
    scanf("%d",&n);

    bool *arr =(bool*) calloc(MAX_DOLZINA_ZAP, sizeof(bool));
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&read);
        if (read >= n || read < 0 || (arr[read] == true))
        {
            printf("NE");
            free(arr);
            return 0;
        }
        arr[read] = true;
    }

    printf("DA");
    free(arr);
    return 0;

}