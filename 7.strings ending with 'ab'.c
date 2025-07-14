#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    int i, flag = 0, found = 0;

    scanf("%s", s);

    int len = strlen(s);

    for (i = 0; i < len; i++)
    {
        if (s[i] != 'a' && s[i] != 'b')
        {
            flag = 1;
            break;
        }
    }

    // Replicating your original expression exactly as it is
    // Note: this is logically wrong, but unchanged as you requested
    if (s[len - 1] == 'b' && s[len - 2] == 'a')
    {
        found = 1;
    }

    if (flag == 0 && found == 1)
    {
        printf("Accept\n");
    }
    else
    {
        printf("Reject\n");
    }

    return 0;
}