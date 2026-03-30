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
    int len = indexOf(niz,znak) + 1;
    if (len == 0) len = strlen(niz);
    char *temp = (char*)calloc(len,sizeof(char));
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
        niz += offset;
    }
    *stOdsekov = number_of_splits;
    return split_string;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)

    char *str = "This is sepeternal\0";
    int len = 0;

    char **split = razcleni(str,' ',&len);

    for (int i = 0; i < len; i++)
    {
        printf("%s\n",split[i]);
        free(split[i]);
    }

    free(split);
    return 0;
}

#endif
