
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naloga1.h"

typedef struct _vo_vec {
    int size;
    int last;
    VO** vec;
} vo_vec;

VO* get(const vo_vec* vec,int i)
{
    if (vec == NULL) return NULL;
    return vec->vec[i];
}

void resizeVector(vo_vec* vec)
{
    if (vec == NULL) return;
    VO** arr = (VO**)malloc(sizeof(VO*) * 2*(vec->size));
    for (int i = 0; i < vec->size; i++)
        arr[i] = get(vec,i);
    vec->size = 2*(vec->size);

    vec->vec = arr;
}

bool add(vo_vec* vec, VO* vo)
{
    if (vec == NULL) return false;
    if (vec->last >= vec->size)
        resizeVector(vec);
    vec->vec[vec->last] = vo;
    vec->last++;
    return true;
}

VO* createVO(Student* s, PO* pred)
{
    VO* vo = (VO*)malloc(sizeof(VO));
    vo->vpisna = s->vpisna;
    vo->ocena = pred->ocena;
    return vo;
}

bool containsSubject(Student* s, char* subject, int* sub_idx)
{
    for (int i = 0; i < s->stPO; i++)
        if (strcmp(s->po[i].predmet, subject) == 0)
        {
            *sub_idx = i;
            return true;
        }
    return false;
}

VO** opravili(Student** studentje, int stStudentov, char* predmet, int* stVO) {
    // popravite / dopolnite ...
    int len = 0;
    for (int i = 0; i < stStudentov; i++)
    {
        int sub_idx = 0;
        if (containsSubject(studentje[i], predmet, &sub_idx) && studentje[i]->po[sub_idx].ocena >= 6)
            len++;
    }

    return NULL;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)
    return 0;
}

#endif
