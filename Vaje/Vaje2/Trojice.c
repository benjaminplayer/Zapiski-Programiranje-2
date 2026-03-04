#include<stdio.h>
#include <math.h> // pri compilation moras NUJNO linkat math lib: -lm (-l system lib; m -> ime lib)

void pitagn3()
{
    int m,n;
    int count = 0;
    int prev = 0, calc = 0;
    scanf("%d%d",&m,&n); //pri stringu ni treba dat &

    for (int i = m; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n;k++)
                if ((calc = (j*j + k*k)) == i*i && calc != prev)
                {
                    prev = calc;
                    //printf("j^2:%d k^2:%d i^2:%d\n",j*j,k*k,i*i);
                    count++;
                }
        prev = 0;
    }

    printf("%d",count);
}

int main()
{
    int m,n;
    int count = 0;
    int prev = 0, calc = 0;
    scanf("%d%d",&m,&n); //pri stringu ni treba dat &

    for (int i = m; i <= n; i++)
    {
        // a = c^2/rt(2)
        for (int j = 1; j <= n; j++)
        {
            int b2 = i * i - j * j;
            int b = round(sqrt(b2));
            if (b * b == b2)
            {
                count++; // preveri, da je b int
                break;
            }
        }
    }

    printf("%d",count);
    return 0;
}