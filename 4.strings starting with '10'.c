#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    int i, flag = 0;

    scanf("%s", s);

    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] != '0' && s[i] != '1')
        {
            flag = 1;
            break;
        }
    }

    if (flag == 0 && s[0] == '1' && s[1] == '0')
    {
        printf("Accept\n");
    }
    else
    {
        printf("Reject");
    }

    return 0;
}