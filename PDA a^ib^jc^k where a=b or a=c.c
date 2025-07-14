#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    char stack[100];
    int i, top = -1;
    int count = 0, counta = 0, countb = 0, countc = 0;

    printf("Enter the string : ");
    scanf("%s", s);

    int len = strlen(s);

    // Count characters and check invalid characters
    for (i = 0; i < len; i++)
    {
        if (s[i] == 'a')
            counta++;
        else if (s[i] == 'b')
            countb++;
        else if (s[i] == 'c')
            countc++;
        else
            count = 1; // invalid character
    }

    i = 0;
    top = -1;

    // Push 'a's onto stack
    while (i < len && s[i] == 'a')
    {
        stack[++top] = 'a';
        i++;
    }

    if (counta == countb)
    {
        // Pop stack for each 'b'
        while (i < len && s[i] == 'b')
        {
            if (top == -1)
                break;
            top--;
            i++;
        }
        // Then accept all 'c's
        while (i < len && s[i] == 'c')
        {
            i++;
        }
    }
    else if (counta == countc)
    {
        // Skip all 'b's
        while (i < len && s[i] == 'b')
        {
            i++;
        }
        // Pop stack for each 'c'
        while (i < len && s[i] == 'c')
        {
            if (top == -1)
                break;
            top--;
            i++;
        }
    }

    if (count == 1)
    {
        printf("You put wrong Alphabets\n");
    }
    else if (top == -1 && i == len)
    {
        printf("Accepted\n");
    }
    else
    {
        printf("Rejected\n");
    }

    return 0;
}