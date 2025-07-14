#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    scanf("%s", s);

    int count = 0;
    int flagB = 0;
    int flag = 0;
    int len = strlen(s);

    for (int i = 0; i < len; i++)
    {
        if (s[i] == 'a' || s[i] == 'b')
        {
            flag = 0;

            if (s[len] == 'b')
            {
                flagB = 0;
            }
            else if (s[i] == 'a')
            {
                count++;
            }
        }
        else
        {
            flag = 1;
            break;
        }
    }

    if ((count % 2 != 0 || flagB == 0) && flag == 0)
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}