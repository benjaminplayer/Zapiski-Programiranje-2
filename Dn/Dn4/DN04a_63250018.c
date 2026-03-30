#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int n;
    scanf("%d",&n);

    int *seq1 = (int*) calloc(n,sizeof(int));
    int *seq2 = (int*) calloc(n,sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d",&seq1[i]);
    for (int i = 0; i < n; i++)
        scanf("%d",&seq2[i]);

    int *seq2_ptr = &seq2[0];
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        //reset if not equal
        if (*seq2_ptr != seq1[i])
        {
            if (seq2_ptr != &seq2[0])
            {
                seq2_ptr = &seq2[0];
                i--;
            }
            idx = i + 1;

        }
        else
            seq2_ptr++; // inc the pointer if equal

    }

    printf("%d\n",idx);

    free(seq1);
    free(seq2);

}
