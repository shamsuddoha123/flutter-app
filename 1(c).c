#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    int i, count = 0, count0 = 0;

    printf("Enter the string : ");
    scanf("%s", s); // reads input until whitespace

    int len = strlen(s);

    for (i = 0; i < len; i++)
    {
        if (s[i] == '0')
            count0++;
        else if (s[i] == '1')
            continue;
        else
        {
            count = 1; // invalid character
            break;
        }
    }

    if (count == 1)
    {
        printf("You put wrong alphabets.\n");
    }
    else if (count0 == 3)
    {
        printf("Accepted\n");
    }
    else
    {
        printf("Rejected\n");
    }

    return 0;
}