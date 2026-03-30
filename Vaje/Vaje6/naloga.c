#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naloga.h"

int steviloZnakov(char* niz, char znak) {
    // popravite / dopolnite ...
    int count = 0;
    while (*niz != '\0')
    {
        if (*niz == znak) count++;
        niz++;
    }
    return count;
}

int indexOf(char *str, char c)
{
    int count = 0;
    while (*str != '\0')
    {
        if (*str == c) return count;
        str++;
        count++;
    }

    return -1;
}


char* kopirajDoZnaka(char* niz, char znak) {
    // popravite / dopolnite ...
    int len = indexOf(niz,znak);
    if (len == -1) len = strlen(niz);
    char *temp = (char*)calloc(len + 1,sizeof(char));
    for (int i = 0; i < len; i++)
    {
        temp[i] = *niz;
        niz++;
    }

    temp[len] = '\0';

   // if (strlen(niz) != i) temp[i+1] = '\0';
    return temp;
}

char** razcleni(char* niz, char locilo, int* stOdsekov) {
    // popravite / dopolnite ...

    int number_of_splits = steviloZnakov(niz,locilo) + 1;
    char **split_string = calloc(number_of_splits,sizeof(char*));
    for (int i = 0; i < number_of_splits; i++)
    {
        split_string[i] = kopirajDoZnaka(niz,locilo);
        int offset = strlen(split_string[i]);
        niz += offset+1; //offset + 1 bc space :)
    }
    *stOdsekov = number_of_splits;
    return split_string;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)

    char *niz = "prijazen niz z enim samim presledkom med besedami\0";
    int stOdsekov = 0;
    char** odseki = razcleni(niz, ' ', &stOdsekov);
    for (int i = 0;  i < stOdsekov;  i++) {
        printf("%d: <%s>\n", i + 1, odseki[i]);
        free(odseki[i]);
    }
    free(odseki);
    return 0;
}

#endif
