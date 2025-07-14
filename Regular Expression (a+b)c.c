#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];

    printf("Enter a string:\n");
    scanf("%s", s);
    int len = strlen(s);

    // Check for valid length
    if (len != 2)
    {
        printf("rejected\n");
        return 0;
    }

    // Check valid characters
    if ((s[0] == 'a' || s[0] == 'b') && s[1] == 'c')
    {
        printf("accepted\n");
    }
    else
    {
        printf("rejected\n");
    }

    return 0;
}