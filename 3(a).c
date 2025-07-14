#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    int i, count = 0, flag = 0;

    printf("Enter the string : ");
    scanf("%s", s);

    int len = strlen(s);

    // Check for invalid characters
    for (i = 0; i < len; i++)
    {
        if (s[i] != '0' && s[i] != '1')
        {
            count = 1;
            break;
        }
    }

    // DFA simulation based on flag transitions
    for (i = 0; i < len; i++)
    {
        if (flag == 0)
        {
            if (s[i] == '0')
                flag = 0;
            else if (s[i] == '1')
                flag = 4;
        }
        else if (flag == 1)
        {
            if (s[i] == '0')
                flag = 0;
            else if (s[i] == '1')
                flag = 4;
        }
        else if (flag == 2)
        {
            if (s[i] == '0')
                flag = 1;
            else if (s[i] == '1')
                flag = 5;
        }
        else if (flag == 3)
        {
            if (s[i] == '0')
                flag = 1;
            else if (s[i] == '1')
                flag = 5;
        }
        else if (flag == 4)
        {
            if (s[i] == '0')
                flag = 2;
            else if (s[i] == '1')
                flag = 6;
        }
        else if (flag == 5)
        {
            if (s[i] == '0')
                flag = 2;
            else if (s[i] == '1')
                flag = 6;
        }
        else if (flag == 6)
        {
            if (s[i] == '0')
                flag = 3;
            else if (s[i] == '1')
                flag = 7;
        }
        else if (flag == 7)
        {
            if (s[i] == '0')
                flag = 3;
            else if (s[i] == '1')
                flag = 7;
        }
    }

    if (count == 1)
        printf("You put wrong alphabets.\n");
    else if (flag == 1 || flag == 3 || flag == 5 || flag == 7)
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}