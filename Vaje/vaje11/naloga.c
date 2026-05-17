
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naloga.h"
#define null NULL
int vsotaI(Vozlisce* zacetek) {
    // popravite / dopolnite ...

    int sum = 0;

    while(zacetek != NULL)
    {
        sum += zacetek->podatek;
        zacetek = zacetek->naslednje;
    }
    return sum;
}

int vsotaR(Vozlisce* zacetek) {
    if (zacetek == NULL) return 0;
    return zacetek->podatek + vsotaR(zacetek->naslednje);
}

Vozlisce* creatNodeInt(int const val, Vozlisce* next)
{
    Vozlisce* node = (Vozlisce*) malloc(sizeof(Vozlisce));
    node->podatek = val;
    node->naslednje = next;
    return node;
}

Vozlisce* vstaviUrejenoI(Vozlisce* zacetek, int element) {
    // popravite / dopolnite ...
    // dodajanje na start
    if (zacetek == NULL || element < zacetek->podatek)
    {
        return creatNodeInt(element,zacetek);
    }

    Vozlisce* tmp = zacetek;

    while (tmp->naslednje != null && tmp->naslednje->podatek < element) //pointa na tocno mesto kjer more bit
        tmp = tmp->naslednje;                     //oz next element


    tmp->naslednje = creatNodeInt(element,tmp->naslednje);

    return zacetek;
}

Vozlisce* vstaviUrejenoR(Vozlisce* zacetek, int element)
{
    if (zacetek == NULL || element < zacetek->podatek)
        return creatNodeInt(element,zacetek);
    zacetek->naslednje = vstaviUrejenoR(zacetek->naslednje,element);
    return zacetek;
}

#ifndef test

Vozlisce* genList(int elm[], int size)
{
    Vozlisce* v = (Vozlisce*) malloc(sizeof(Vozlisce));
    v->podatek = elm[size-1];
    for (int i = size - 2; i >= 0; i--)
    {
        Vozlisce* next = (Vozlisce*)malloc(sizeof(Vozlisce));
        next->podatek = elm[i];
        next->naslednje = v;
        v = next;
    }
    return v;
}

void print(Vozlisce* v)
{
    while (v != NULL)
    {
        printf("%d, ",v->podatek);
        v = v->naslednje;
    }
}

void freeList(Vozlisce* v)
{
    Vozlisce* next = v->naslednje;
    while (next != NULL)
    {
        next = v->naslednje;
        free(v);
        v= next;
    }
}

int main() {

    int arr[] = {1,2,3,5,6,7,8,9,10};
    Vozlisce* v = genList(arr,9);
    print(v);
    printf("\n");
    //printf("sumI: %d; sumR: %d",vsotaI(v), vsotaR(v));
    vstaviUrejenoR(v,4);
    print(v);
    freeList(v);
    return 0;
}

#endif
