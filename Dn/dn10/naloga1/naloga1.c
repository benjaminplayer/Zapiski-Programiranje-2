
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naloga1.h"

VO* createVO(Student* s, PO pred)
{
    VO* vo = (VO*)malloc(sizeof(VO));
    vo->vpisna = s->vpisna;
    vo->ocena = pred.ocena;
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

void freeArr(VO** arr, int len)
{
    for (int i = 0; i < len; i++)
        free(arr[i]);
    free(arr);
}

void orderArray(VO** arr, int const len)
{
    if (arr == NULL) exit(1);
    for (int i = 0; i < len; i++)
    {
        int mxIdx = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j]->ocena > arr[mxIdx]->ocena)
                mxIdx = j;
        }

        if (mxIdx == i) continue;
        VO* tmp = arr[i];
        arr[i] = arr[mxIdx];
        arr[mxIdx] = tmp;

    }

    for (int i = 0; i < len - 1; i++)
    {
        int sub_len = 0;
        for (int j = i; j < len - 1 && arr[j]->ocena == arr[j+1]->ocena;j++) sub_len++;

        // printf("sub_len: %d\n", sub_len);
        if (sub_len == 0) continue;
        sub_len++;
        // printf("alt_sub_len: %d\n", sub_len);

        for (int j = i; j < sub_len; j++)
        {
            int mxIdx = i;
            for (int k = j + 1; k < sub_len; k++)
            {
                if (arr[k]->vpisna > arr[mxIdx]->vpisna)
                    mxIdx = k;
            }

            if (mxIdx == j) continue;
            VO* tmp = arr[j];
            arr[j] = arr[mxIdx];
            arr[mxIdx] = tmp;
        }
        i += sub_len;

    }

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

    *stVO = len;

    VO** arr = (VO**)malloc(sizeof(VO*) * len);
    int c = 0;
    for (int i = 0 ; i < stStudentov; i++)
    {
        int sub_idx = 0;
        if (containsSubject(studentje[i], predmet, &sub_idx) && studentje[i]->po[sub_idx].ocena >= 6)
            arr[c++] = createVO(studentje[i], studentje[i]->po[sub_idx]);

    }
    orderArray(arr, len);
    return arr;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)

    return 0;
}

#endif
