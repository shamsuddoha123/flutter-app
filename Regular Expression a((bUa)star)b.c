#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    int len;

    printf("Enter a string:\n");
    scanf("%s", s);
    len = strlen(s);

    // Check for invalid characters
    for (int i = 0; i < len; i++)
    {
        if (s[i] != 'a' && s[i] != 'b')
        {
            printf("invalid input\n");
            return 0;
        }
    }

    // Minimum length must be 2 (at least 'ab')
    if (len < 2)
    {
        printf("rejected\n");
        return 0;
    }

    // Check start with 'a' and end with 'b'
    if (s[0] == 'a' && s[len - 1] == 'b')
    {
        printf("accepted\n");
    }
    else
    {
        printf("rejected\n");
    }

    return 0;
}