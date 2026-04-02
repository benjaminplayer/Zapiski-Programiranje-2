
/*

Prevajanje in poganjanje skupaj z datoteko test01.c:

gcc -D=test test01.c naloga2.c
./a.out


*/

#include <stdio.h>
#include "naloga2.h"

void zamenjaj(int** a, int** b) {
    // dopolnite ...
    int const temp = **a;
    **a = **b;
    **b = temp;
}

//do later
void uredi(int** a, int** b, int** c) {
    // dopolnite ...
    //idea: swap elements, so the min element is always fist, then repeat for other two,
    //than finally compare the first and the second element
    if (**b < **a) zamenjaj(a, b);
    if (**c < **b) zamenjaj(b, c);
    if (**b < **a) zamenjaj(a, b);

}

#ifndef test

int main() {

    int a = 4, b = 7, c = 6;
    int *pa = &a, *pb = &b, *pc = &c;

    printf("a: %d, b: %d,c: %d\n",*pa,*pb,*pc);
    uredi(&pa, &pb, &pc);
    printf("a: %d, b: %d,c: %d\n",*pa,*pb,*pc);
    return 0;
}

#endif
