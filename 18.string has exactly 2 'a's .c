#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    scanf("%s", s);

    int count = 0;
    int flag = 0;
    int len = strlen(s);

    for (int i = 0; i < len; i++)
    {
        if (s[i] == 'a' || s[i] == 'b')
        {
            if (s[i] == 'a')
            {
                count++;
            }
            flag = 0;
        }
        else
        {
            flag = 1;
        }
    }

    if (flag == 0 && count == 2)
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}