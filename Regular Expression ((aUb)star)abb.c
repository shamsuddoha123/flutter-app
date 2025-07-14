#include <stdio.h>
#include <string.h>
int main()
{
    int count = 0;
    char s[100];

    printf("Enter a string: \n");
    scanf("%s", s);
    int len = strlen(s);

    for (int i = 0; i < len; i++)
    {
        if (s[i] == 'a' || s[i] == 'b')
        {
            count++;
        }
    }

    if (count != len)
    {
        printf("invalid input\n");
        return 0;
    }

    if (s[len - 1] == 'b' && s[len - 2] == 'b' && s[len - 3] == 'a')
    {
        printf("accepted\n");
    }
    else
    {
        printf("rejected\n");
    }
    return 0;
}









