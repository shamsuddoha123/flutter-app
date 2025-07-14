#include <stdio.h>
#include <string.h>

int main()
{
    char s[1000];
    int i, count = 0;

    printf("Enter the string : ");
    scanf("%s", s);

    int len = strlen(s);

    for (i = 0; i < len; i++)
    {
        if (s[i] == 'a' || s[i] == 'b')
            continue;
        else
        {
            count = 1;
            break;
        }
    }

    if (count == 1)
        printf("You put wrong alphabets.\n");
    else if (len >= 3 && s[len - 3] == 'a')
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}
