#include <stdio.h>
#include <stdbool.h>

int readInt()
{
    int c;
    int i = 0;
    
    while (true)
    {
        c = getchar(); // prebere znak iz tipkovnice in ga vrne kot int
        if (('0' <= c) && (c <= '9'))
            i = i*10 + (c-'0');
        else
            break;
    }

    return i;
}

int main()
{
    printf("int = %d\n",readInt());
    return 0;
}
