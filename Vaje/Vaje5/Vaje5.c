#include <stdio.h>
#include <stdlib.h>
int vsota(const int* zac, const int* kon)
{
    int sum = 0;
    for (;zac <= kon;zac++)
        sum += *zac;
    return sum;
}

void indeksInKazalec(int* t, int* indeks, int** kazalec)
{
    if (*indeks == -1)
        *indeks = *kazalec - t;
    else
        *kazalec = (t + *indeks);
}
void frekvenceCrk(char* niz, int** frekvence)
{
    int *freq = (int*)(calloc(26,sizeof(int))); //calloc ti da auto na 0

    while (*niz != '\0')
    {
        if (*niz >= 'A' && *niz <= 'Z') *(freq + (*niz - 'A')) += 1;
        else if (*niz >= 'a' && *niz <= 'z') *(freq + (*niz - 'a')) += 1;
        niz++;
    }

    *frekvence = freq;
}
//rarw
//ne dela yet
int **preoblikuj(int **t, int stVrstic)
{
    int el = 0;
    while (t != NULL)
    {
        while (**t != 0)
        {
            el++;
            *t = *t + 1;
        }
        printf("\n");
        t++;
    }
    printf("%d",el);
}
#ifndef test
int main(int argc, char *argv[])
{
    /*int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int indeks = 6;
    int *p = &arr[3];
    int **kazalec = &p;
    //printf("%d\n", vsota(&arr[0],&arr[9]));
    indeksInKazalec(&arr[0], &indeks, kazalec);
    printf("indeks: %d; pointer: %d",indeks, **kazalec);*/

    /*char string[] = "baNanA\0";
    int* ferq = NULL;

    frekvenceCrk(string, &ferq);
    for (int i = 0; i < 26 ;i++)
        printf("%c: %d; ",i+ 'A',(*(ferq + i)));

    if (ferq != NULL) free(ferq);*/
    int a1[6] = {10,20,30,40,50,0};
    int a2[4] = {60,70,80,0};
    int a3[6] = {90,100,110,120,130,0};

    int **p = malloc(4* sizeof(int*));
    *p = a1;
    *(p+1) = a2;
    *(p+2) = a3;
    *(p+3) = NULL;

    preoblikuj(p,4);

    for (int i = 0; i < 4; i++)
        free((p+i));
    free(p);
}
#endif