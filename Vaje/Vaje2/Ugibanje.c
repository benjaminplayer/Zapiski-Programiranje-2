#include <stdio.h>

int main()
{
    int lbound, hbound, guess = 0, read;
    scanf("%d%d",&lbound,&hbound);
    //printf("lbound: %d hbound %d\n",lbound,hbound);
    while (scanf("%d",&read) == 1 && lbound <= hbound)
    {
        //ce je st manjse
        guess = (lbound + hbound) / 2;

        switch (read)
        {
            case 0:
                printf("%d",guess);
                return 0;
            case 1:
                lbound = guess + 1;
                break;
            case -1:
                hbound = guess - 1;
                break;
        }
    }

    if (lbound > hbound) printf("PROTISLOVJE");
    else if (lbound < hbound) printf("%d %d",lbound, hbound);
    else printf("%d",guess);
    return 0;
}