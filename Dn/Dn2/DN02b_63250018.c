#include <stdio.h>
#include <stdbool.h>

void readUntilNextToken(void)
{
    while (getchar() != ' ');
}

int main(int argc, char *argv[])
{
    char c, first_char = 0, second_char = 0;
    int readChars = 1;
    while ((c = getchar()) != '\n')
    {
        //printf("read chars: %d\n",readChars);

        //get the first character in a string
        if (readChars == 1)
            first_char = c;
        //printf("read char: %c; firstchar: %c\n",c,first_char);
        if (first_char > '0' && first_char <= '9' && c != ' ')
        {
            //printf("first char is: %c\n", first_char);
            if (c < '0' || c > '9')
            {
                putchar('0');
                readUntilNextToken();
                readChars = 0;

            }
        }
        else if (first_char == '0' && c != ' ')
        {
            //printf("read chars: %d, current char: %c\n",readChars, c);
            if (readChars < 2)
            {
                readChars++;
                continue;
            }

            if (readChars == 2)
                second_char = c;
            if (second_char == 'x')
            {
                if (readChars == 2)
                {
                    readChars++;
                    continue;
                }
                if (!((c >= '0' && c <='9') || (c >= 'A' && c<='F')))
                {
                    putchar('0');
                    readChars = 0;
                    first_char = 0;
                    second_char = 0;
                    readUntilNextToken();
                    //second_char = 0;
                }
            }
            else if (second_char == 'b')
            {
                if (readChars == 2)
                {
                    readChars++;
                    continue;
                }
                if (c < '0' || c > '1')
                {
                    putchar('0');
                    readChars = 0;
                    first_char = 0;
                    second_char = 0;
                    readUntilNextToken();
                    //second_char = 0;
                }
            }else
            {
                if (c < '0' || c > '7')
                {
                    putchar('0');
                    readChars = 0;
                    readUntilNextToken();
                }

            }
        }
        else if (c ==' ')
        {
            putchar('1');
            readChars = 0;
            first_char = 0;
            second_char = 0;
        }
        else
        {
            putchar('0');
            readChars = 0;
            first_char = 0;
            second_char = 0;
            readUntilNextToken();
        }
        readChars++;
    }

    //pass ? putchar('1') : putchar('0');

}
