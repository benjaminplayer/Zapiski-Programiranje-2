
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "naloga.h"
#define null NULL

int poisciStudenta(Student** studentje, int stStudentov, int vpisna)
{
    for (int i = 0; i < stStudentov; i++)
        if (studentje[i]->vpisna == vpisna) return i;
    return -1;
}

int poisciPO(Student* student, const char* predmet) {
    // popravite / dopolnite ...

    for (int i = 0; student->po[i].predmet[0] != '\0'; i++)
        if (strcmp(student->po[i].predmet,predmet) == 0) return i;
    return -1;
}

int dodaj(Student** studentje, int stStudentov, int vpisna, char* predmet, int ocena) {
    // popravite / dopolnite ...
    int idx = poisciStudenta(studentje, stStudentov, vpisna);
    if (idx != -1)
    {
        Student* student = studentje[idx];
        int po_idx = poisciPO(student, predmet);
        if (po_idx != -1) student->po[po_idx].ocena = ocena;
        else
        {
            PO* po = (PO*)calloc(1,sizeof(PO));
            strcpy(po->predmet, predmet);
            po->ocena = ocena;

            int len = 0;
            while (student->po[len].predmet[0] != '\0')
            {
                len++;
            }
            student->po[len] = *po;

            free(po);
        }
        return stStudentov;
    }

    PO* pred = (PO*)malloc(sizeof(PO));
    strcpy(pred->predmet,predmet);
    pred->ocena = ocena;

    //Student st = {vpisna, arr, ocena};
    Student* st = (Student*)malloc(sizeof(Student));
    st->vpisna = vpisna;
    st->po = pred;
    st->stPO = 1;
    studentje[stStudentov] = st;
    studentje[stStudentov+1] = null;

    return stStudentov + 1;
}
//#define test
#ifndef test

void izpisi(Student** studentje, int stStudentov) {
    for (int i = 0;  i < stStudentov;  i++) {
        printf("%d: [", studentje[i]->vpisna);
        int stPO = studentje[i]->stPO;
        PO* po = studentje[i]->po;
        for (int j = 0;  j < stPO;  j++) {
            if (j > 0) {
                printf(", ");
            }
            printf("%s/%d", po[j].predmet, po[j].ocena);
        }
        printf("]\n");
    }
    printf("\n");
}

void pocisti(Student* student) {
    free(student->po);
    free(student);
}

int main() {
    // koda za ro"cno testiranje (po "zelji)

    Student* studentje[] = {
        (Student[]) {333, (PO[]){{"FIZ", 10}, {"P1", 7}, {"P2", 8}, {"ODV", 9}, {"", 0}}, 4},
        (Student[]) {888, (PO[]){{"", 0}}, 0},
        (Student[]) {555, (PO[]){{"ARS", 6}, {"P2", 8}, {"ODV", 9}, {"", 0}}, 3},
        (Student[]) {111, (PO[]){{"OMA", 9}, {"", 0}}, 1},
        (Student[]) {777, (PO[]){{"P1", 10}, {"P2", 7}, {"", 0}}, 2},
        NULL
    };
    int stStudentov = sizeof(studentje) / sizeof(studentje[0]) - 1;

    izpisi(studentje, stStudentov);
    stStudentov = dodaj(studentje, stStudentov, 111, "ODV", 7);
    izpisi(studentje, stStudentov);



    return 0;
}

#endif
