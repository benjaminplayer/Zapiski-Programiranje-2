#include <stdio.h>
#include <stdlib.h>

void output(int n, char* str, char c1, char c2, int idx)
{
    if (idx == n) return;
    for (char c = c1; c <= c2; ++c)
    {
        str[idx] = c;
        str[idx+1] = '\0';
        printf("%s\n", str);

        output(n, str, c1, c2, idx+1);
    }
}

int main(int argc, char *argv[])
{
    int n;
    char c1, c2;

    scanf("%d %c %c",&n, &c1, &c2);

    char* str = (char*)calloc(n + 1, sizeof(char));

    output(n,str,c1,c2,0);

    free(str);

    return 0;
}