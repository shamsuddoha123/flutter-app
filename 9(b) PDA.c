#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    char stack[100];
    int top = -1;
    int count = 0;
    int i;

    printf("Enter a string: ");
    scanf("%s", s);

    int len = strlen(s);

    // Check for invalid characters (only 'a', 'b', 'C' allowed)
    for (i = 0; i < len; i++)
    {
        if (s[i] != 'a' && s[i] != 'b' && s[i] != 'C')
        {
            count = 1;
            break;
        }
    }

    // Push first half characters onto stack
    for (i = 0; i < len / 2; i++)
    {
        stack[++top] = s[i];
    }

    // Skip the middle character (should be 'C')
    i++;

    // Compare second half characters with stack top
    while (i < len && top >= 0 && s[i] == stack[top])
    {
        top--;
        i++;
    }

    if (count == 1)
    {
        printf("You put wrong alphabets\n");
    }
    else if (top == -1 && s[len / 2] == 'C')
    {
        printf("Accepted\n");
    }
    else
    {
        printf("Rejected\n");
    }

    return 0;
}