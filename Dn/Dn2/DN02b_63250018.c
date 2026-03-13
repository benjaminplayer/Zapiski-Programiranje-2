#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 123 10001 04856 9 0 1234a 00
// 1101100

void readUntilNextToken(void)
{
    char c;
    while ((c = getchar()) != ' ')
    {
        if (c == '\n')
            exit(0);
    }
}
bool reachedNewLine = false, endOfToken = false;

bool stateB(int len, char c);

bool universalState(int len,const char c, const char bound1, const char bound2)
{
    if (c == ' ')
    {
        endOfToken = true;
        return true;
    }
    if (c == '\n')
    {
        reachedNewLine = true;
        return true;
    }
    if (c >= bound1 && c <= bound2)
        return universalState(++len,getchar(), bound1, bound2);
    return false;
}

bool stateD(int len, const char c)
{
    if (c == ' ' && len > 2)
    {
        endOfToken = true;
        return true;
    }
    if (c == '\n')
    {
        reachedNewLine = true;
        if (len > 2) return true;
    }
    else if (c >= '0' && c <= '1')
        return stateD(++len,getchar());
    if (c == ' ') endOfToken = true;
    return false;

}

bool hexState(int len, const char c)
{
    if (c == ' ' && len > 2)
    {
        endOfToken = true;
        return true;
    }
    if (c == '\n')
    {
        reachedNewLine = true;
        if (len > 2) return true;
    }
    else if (c >= '0' && c <= '9' || c >= 'A' && c <= 'F')
        return hexState(++len,getchar());
    if (c == ' ') endOfToken = true;
    return false;

}

bool stateA(const char c)
{
    if (c >= '1' && c <= '9')
        return universalState(1,getchar(),'0','9');
    if(c == '0')
        return stateB(1,getchar());
    return false;
}

bool stateB(int len, const char c)
{
    if (c == ' ')
    {
        endOfToken = true;
        return true;
    }
    if (c == '\n')
    {
        reachedNewLine = true;
        return true;
    }
    if (c >= '0' && c <= '7')
        return universalState(++len,getchar(),'0','7');
    if (c == 'x')
        return hexState(++len,getchar());
    if (c == 'b')
        return stateD(++len,getchar());
    return false;
}


int main(int argc, char *argv[])
{
    char c;

    while (!reachedNewLine && (c = getchar()) != '\n')
    {
        const bool res = stateA(c);
        if (res) putchar('1');
        else
        {
            putchar('0');
            if (!endOfToken) readUntilNextToken();
        }

        endOfToken = false; //reset
    }
    return 0;
}
