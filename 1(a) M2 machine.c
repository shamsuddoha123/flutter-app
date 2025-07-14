#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    int i, count = 0, flag = 0;

    printf("Enter the string: ");
    fgets(s, sizeof(s), stdin);

    // Manually remove the newline character '\n' from input
    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '\n')
        {
            s[i] = '\0';
            break;
        }
    }

    int len = strlen(s);

    // Check for epsilon (empty string)
    if (len == 0)
    {
        printf("Accept\n");
        return 0;
    }

    // Check for invalid characters
    for (i = 0; i < len; i++)
    {
        if (s[i] != 'a' && s[i] != 'b')
        {
            count = 1;
            break;
        }
    }

    // DFA simulation
    for (i = 0; i < len; i++)
    {
        if (flag == 0)
        {
            if (s[i] == 'a')
                flag = 0;
            else if (s[i] == 'b')
                flag = 1;
        }
        else if (flag == 1)
        {
            if (s[i] == 'a')
                flag = 3;
            else if (s[i] == 'b')
                flag = 2;
        }
        else if (flag == 2)
        {
            if (s[i] == 'a')
                flag = 3;
            else if (s[i] == 'b')
                flag = 2;
        }
        else if (flag == 3)
        {
            if (s[i] == 'a')
                flag = 1;
            else if (s[i] == 'b')
                flag = 0;
        }
    }

    if (count == 1)
    {
        printf("put wrong alphabet\n");
    }
    else if (flag == 0 || flag == 2)
    {
        printf("Accept\n");
    }
    else
    {
        printf("Reject\n");
    }

    return 0;
}