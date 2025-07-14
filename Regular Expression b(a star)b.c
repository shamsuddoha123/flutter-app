#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];

    printf("Enter a string:\n");
    scanf("%s", s);
    int len = strlen(s);

    // Check for invalid characters
    for (int i = 0; i < len; i++)
    {
        if (s[i] != 'a' && s[i] != 'b')
        {
            printf("invalid input\n");
            return 0;
        }
    }

    // Must start and end with 'b'
    if (s[0] != 'b' || s[len - 1] != 'b')
    {
        printf("rejected\n");
        return 0;
    }

    // All characters between first and last must be 'a' (if any)
    for (int i = 1; i < len - 1; i++)
    {
        if (s[i] != 'a')
        {
            printf("rejected\n");
            return 0;
        }
    }

    printf("accepted\n");
    return 0;
}