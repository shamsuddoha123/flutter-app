#include <stdio.h>
#include <string.h>

int main()
{
    char s[1000];
    scanf("%s", s);
    int flag = 0;
    int len = strlen(s);

    for (int i = 1; i < len; i++)
    {
        if ((s[0] == 'a') && (s[i] == 'a' || s[i] == 'b'))
        {
            flag = 1;
        }
        else
        {
            flag = 0;
            break;
        }
    }

    if (flag == 1)
        printf("accepted\n");
    else
        printf("rejected\n");

    return 0;
}