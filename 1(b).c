#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    int i, count = 0;

    printf("Enter the string : ");
    scanf("%s", s);  // input stops at whitespace

    int len = strlen(s);

    // Check for invalid characters
    for (i = 0; i < len; i++)
    {
        if (s[i] != '0' && s[i] != '1')
        {
            count = 1;
            break;
        }
    }

    if (count == 1)
    {
        printf("You put wrong alphabets.\n");
    }
    else if (s[0] == '0' && len % 2 == 1)
    {
        printf("Accepted\n");
    }
    else if (s[0] == '1' && len % 2 == 0)
    {
        printf("Accepted\n");
    }
    else
    {
        printf("Rejected\n");
    }

    return 0;
}