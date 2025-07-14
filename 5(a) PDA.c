#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    char stack[100];
    int top = -1;
    int count = 0;

    printf("Enter the string : ");
    scanf("%s", s);

    int len = strlen(s);
    int i = 0;

    // Check for invalid characters
    for (i = 0; i < len; i++)
    {
        if (s[i] != 'a' && s[i] != 'b')
        {
            count = 1;
            break;
        }
    }

    if (count == 1)
    {
        printf("You put wrong alphabets\n");
        return 0;
    }

    i = 0;
    // Push 'a's into stack
    while (i < len && s[i] == 'a')
    {
        stack[++top] = s[i];
        i++;
    }

    // Pop stack for every 'b'
    while (i < len && s[i] == 'b')
    {
        if (top == -1)
            break; // No matching 'a' in stack

        top--;
        i++;
    }

    if (top == -1 && i == len)
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}