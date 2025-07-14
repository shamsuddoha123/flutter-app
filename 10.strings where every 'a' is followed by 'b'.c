#include <stdio.h>
#include <string.h>

int main()
{
    char s[105];
    int flag = 0;

    // Read input including empty string (newline)
    if (fgets(s, sizeof(s), stdin) == NULL) {
        // If reading fails, treat as empty
        s[0] = '\0';
    }

    // Remove trailing newline, if present
    int len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
        len--;
    }

    // If input is empty string
    if (len == 0) {
        printf("Accepted\n");
        return 0;
    }

    for (int i = 0; i < len; i++)
    {
        if (s[i] != 'a' && s[i] != 'b') {
            flag = 1;
            break;
        }

        if (s[i] == 'a') {
            if (i + 1 >= len || s[i + 1] != 'b') {
                flag = 1;
                break;
            }
        }
    }

    if (flag == 0)
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}