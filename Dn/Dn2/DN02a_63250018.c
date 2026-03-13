#include <stdio.h>
#include <stdbool.h>
bool endOfToken = false, endOfLine = false;

void readUntilNextToken(void)
{
    char c;
    while ((c = getchar())!=' ')
    {
        if (c == '\n')
        {
            endOfLine = true;
            return;
        }
    }
}


bool universalState(int len, const char c)
{
    if (c == ' ')
    {
        endOfToken = true;
        return true;
    }
    if (c == '\n')
    {
        endOfLine = true;
        return true;
    }
    if (c >= '0' && c <= '9')
        return universalState(++len, getchar());
    return false;
}

bool checkZero(int len, const char c)
{
    if (c == '0')
        return false;
    if (c == ' ')
    {
        endOfToken = true;
        return true;
    }
    if (c == '\n')
    {
        endOfLine = true;
        return true;
    }
    return false;
}

bool nodeA(const char c)
{
    if (c >= '1' && c <= '9')
        return universalState(1, getchar());
    if (c == '0')
        return checkZero(1, getchar());
    return false;
}

int main(int argc, char *argv[])
{
    char c;
    while (!endOfLine && (c=getchar())!='\n')
    {
        if (nodeA(c))
            putchar('1');
        else
        {
            putchar('0');
            if (!endOfToken) readUntilNextToken();
        }
        endOfToken = false;

    }
}
