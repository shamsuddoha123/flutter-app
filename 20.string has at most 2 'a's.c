#include <stdio.h>
#include <string.h>

int main()
{
    char s[105];
    int countA = 0;
    int flag = 0; // 0 = valid, 1 = invalid

    if (fgets(s, sizeof(s), stdin) == NULL) {
        s[0] = '\0'; // treat as empty string if input fails
    }

    int len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0'; // remove trailing newline
        len--;
    }

    for (int i = 0; i < len; i++)
    {
        if (s[i] == 'a')
        {
            countA++;
        }
        if (s[i] != 'a' && s[i] != 'b')
        {
            flag = 1; // invalid character
            break;
        }
    }

    if (flag == 0 && countA <= 2)
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}