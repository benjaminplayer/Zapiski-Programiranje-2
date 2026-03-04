#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int a, b, read;
    bool guessed = false;
    scanf("%d%d",&a,&b);
    int lbound = (a < b)? a : b, hbound = (a > b)? a : b, guess = 0;
    //printf("lbound: %d hbound %d\n",lbound,hbound);
    while (scanf("%d",&read)!=EOF && read != -2)
    {
        //ce je st manjse
        guess = floor((lbound + hbound) / 2);
        if (read == 0)
        {
            guessed = true;
            break;
        }

        //printf("g:%d lb:%d hb: %d\n",guess, lbound,hbound);

        if (hbound - lbound == 1)
        {
            printf("PROTISLOVJE");
            return 0;
        }

        if (read < 0)
        {
            hbound = guess;
        }
        else
        {
            lbound = guess;
        }

    }

    if (guessed)
        printf("%d\n",guess);
    else
    {
        guess = floor((lbound + hbound) / 2);
        if (hbound - lbound <= 2)
            printf("%d\n",guess);
        else
            printf("%d %d\n",lbound +1,hbound -1);
    }
    return 0;
}