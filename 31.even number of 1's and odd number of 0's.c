#include <stdio.h>
#include <string.h>

int main()
{
    char s[105];
    int count0 = 0, count1 = 0;
    int flag = 0; // 1 means invalid character found

    // Read entire line including empty string
    if (fgets(s, sizeof(s), stdin) == NULL)
    {
        s[0] = '\0';
    }

    int len = strlen(s);
    // Remove trailing newline if present
    if (len > 0 && s[len - 1] == '\n')
    {
        s[len - 1] = '\0';
        len--;
    }

    for (int i = 0; i < len; i++)
    {
        if (s[i] == '0')
        {
            count0++;
        }
        else if (s[i] == '1')
        {
            count1++;
        }
        else
        {
            flag = 1; // invalid character
            break;
        }
    }

    if (flag == 1)
    {
        printf("Rejected\n");
    }
    else if ((count1 % 2 == 0) && (count0 % 2 == 1))
    {
        printf("Accepted\n");
    }
    else
    {
        printf("Rejected\n");
    }

    return 0;
}