// ques 1(a)
#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    int i, count = 0, flag = 0;

    printf("Enter the string : ");
    scanf("%s", s); // reads input until space or newline

    int len = strlen(s);

    for (i = 0; i < len; i++)
    {
        if (s[i] != 'a' && s[i] != 'b')
        {
            count = 1; // Invalid character
            break;
        }
    }

    for (i = 0; i < len; i++)
    {
        if (flag == 0)
        {
            if (s[i] == 'a')
                flag = 1;
            else if (s[i] == 'b')
                flag = 0;
        }
        else if (flag == 1)
        {
            if (s[i] == 'a' || s[i] == 'b')
                flag = 2;
        }
        else if (flag == 2)
        {
            if (s[i] == 'a')
                flag = 1;
            else if (s[i] == 'b')
                flag = 0;
        }
    }

    if (count == 1)
        printf("You put wrong alphabets.\n");
    else if (flag == 1)
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}