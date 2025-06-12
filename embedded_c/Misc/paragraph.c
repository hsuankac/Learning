#include <stdio.h>

char *buffer = "This is line 1.\nThis is line 2.\nThis is line 3.\nThis is line 4.\n";

typedef char line[40]; // this is number of characters in one line
line lines[20] ;       // this is how many lines

void updateLines(void)
{
    int lineNum = 0, characters = 0;
    while(*buffer != '\0')
    {
        if(*buffer == '\n')
        {
            lines[lineNum][characters] = '\n';
            characters = 0;
            lineNum++;
        }
        else
        {
            lines[lineNum][characters++] = *buffer;
        }
        buffer++;
    }
}

void printLine(int num)
{
    printf("%s", lines[num]);
}

int main()
{
    updateLines();
    printLine(2);

    return 0;
}