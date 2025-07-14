#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    int i, flag;
    scanf("%s", s);

    int len = strlen(s);

    for (i = 0; i < len; i++)
    {
        if (s[i] == 'b' && s[i+1] == 'a' && s[i+2] == 'b' && s[i+3] == 'a')
        {
            flag = 0;
        }
        else if (s[i] != 'a' && s[i] != 'b')
        {
            flag = 1;
            break;
        }
    }

    if (flag == 0)
    {
        printf("Accept\n");
    }
    else
    {
        printf("Reject\n");
    }

    return 0;
}