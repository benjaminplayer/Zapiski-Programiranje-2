//
// Created by benja on 26. 02. 2026.
//
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool dir_exists(const char* dir)
{
    struct stat stats;
    if (stat(dir, &stats) == 0)
        return S_ISDIR(stats.st_mode);
    return false;
}

int indexOf(char *s, char c)
{
    for (int i = 0; i < strlen(s); i++)
        if (s[i] == c)
            return i;
    return -1;
}

int indexOfFrom(char *s, char c, int start)
{
    for (int i = start; i < strlen(s); i++)
        if (s[i] == c)
            return i;
    return -1;
}

int lastIndexOf(char *s, char c)
{
    int idx = 0;
    int tmp = indexOf(s, c);
    while (tmp != -1)
    {
        idx = tmp;
        tmp = indexOfFrom(s, c,tmp+1);
    }

    return idx;
}

char* substr(char *src, int start, int end)
{
    char *dest = (char*)malloc(end - start + 1);
    for (int i = start; i <end; i++)
        dest[i-start] = src[i];
    dest[end] = '\0';
    return dest;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Missing arguments! Expected: runTests program_path test_dir_path\n");
        return 1;
    }
    char copyCfile[1024];
    char copyTests[1024];

    if (!dir_exists("./res"))
    {
        const int exit_code_dir_creation = system("mkdir res");
        if (exit_code_dir_creation != 0)
        {
            printf("Error creating testing directory\n");
            return 1;
        }
    }
    // snprintf safely formats the string and prevents overflows
    // Note the spaces added inside the format string
    snprintf(copyCfile, sizeof(copyCfile), "cp %s ./res", argv[1]);
    snprintf(copyTests, sizeof(copyTests), "cp -a %s/. ./res", argv[2]);

    const int return_code_c_copy = system(copyCfile);
    if (return_code_c_copy != 0)
    {
        perror("Error while trying to copy a C file\n");
        return 1;
    }

    const int return_code_tests = system(copyTests);
    if (return_code_tests != 0)
    {
        perror("Error while trying to copy a Test file directory\n");
        return 1;
    }
    char setVarName[1024];
    char *name = substr(argv[1], 0, strlen(argv[1]) - 2);
    char *sub = substr(argv[1], lastIndexOf(argv[1],'/') + 1, strlen(argv[1])- 2);
    printf("Running test %s\n", name);
    printf("sub = %s\n", sub);
    free(name);
    snprintf(setVarName, sizeof(setVarName), "cd res && export name=%s && make && make test", sub);
    printf("setVarName = %s\n", setVarName);
    free(sub);

    if (system(setVarName) != 0)
    {
        perror("Error while trying to run tests\n");
        return 1;
    }

    return 0;
}
