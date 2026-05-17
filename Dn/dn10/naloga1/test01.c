
#include <stdio.h>
#include <stdlib.h>

#include "naloga1.h"

void izvedi(Student** studentje, int stStudentov, char* predmet) {
    int stVO = 0;
    VO** vvo = opravili(studentje, stStudentov, predmet, &stVO);
    printf("[");
    for (int i = 0;  i < stVO;  i++) {
        VO* vo = vvo[i];
        if (i > 0) {
            printf(", ");
        }
        printf("%d/%d", vo->vpisna, vo->ocena);
    }
    printf("]\n");
}

int main() {
    Student* studentje[] = {
        (Student[]) {
            888,
            (PO[]){{"FIZ", 10}, {"P1", 7}, {"P2", 8}, {"OMA", 5}, {"ODV", 9}},
            5
        },
        (Student[]) {
            333,
            (PO[]){{"", 0}},
            0
        },
        (Student[]) {
            555,
            (PO[]){{"FIZ", 6}, {"P2", 8}, {"ARS", 5}, {"ODV", 9}},
            4
        },
        (Student[]) {
            111,
            (PO[]){{"P1", 7}, {"ARS", 6}},
            2
        },
        (Student[]) {
            777,
            (PO[]){{"P1", 10}, {"FIZ", 7}, {"ODV", 8}},
            3
        },
    };
    int stStudentov = sizeof(studentje) / sizeof(studentje[0]);

    izvedi(studentje, stStudentov, "FIZ");
    izvedi(studentje, stStudentov, "P1");
    izvedi(studentje, stStudentov, "P2");
    izvedi(studentje, stStudentov, "ODV");
    izvedi(studentje, stStudentov, "ARS");
    izvedi(studentje, stStudentov, "OMA");
    izvedi(studentje, stStudentov, "DS");

    return 0;
}
