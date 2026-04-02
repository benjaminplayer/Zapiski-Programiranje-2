
/*

Prevajanje in poganjanje skupaj z datoteko test01.c:

gcc -D=test test01.c naloga1.c
./a.out

*/

#include <stdio.h>
#include <stdlib.h>

#include "naloga1.h"

// 0 1 2 3 4 5 0 8 9 0 1 0 0 2
// *t = 3;
int* poisci(int* t, int* dolzina, int** konec)
{
    // postavi na zacetek
    while (*t != 0) t--;
    int len = 0;
    for (int i = 0; t[i + 1] != 0; i++) len++;
    *dolzina = len;
    *konec = t+len;
    return t+1;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)
    int arr[] = {0,1,2,3,4,5,0,8,9,0,10,21,0};
    int *t = arr + 7;
    int dolzina = 0;
    int* konec = NULL;

    int *found = poisci(t, &dolzina, &konec);
    printf("prvi: %d, len: %d, last: %d",*found, dolzina,*konec);
    return 0;
}

#endif