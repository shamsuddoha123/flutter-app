#include <stdio.h>
#include <string.h>

int main()
{
    char s[1000];
    int i, count = 0;

    printf("Enter the string : ");
    scanf("%s", s);  // does not accept empty string

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
    else if (len >= 2 && s[len - 2] == 'a')
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}