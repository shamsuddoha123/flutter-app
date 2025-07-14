#include <stdio.h>
#include <string.h>

int main()
{
    char s[105];
    int flag = 0;

    // Read full line including empty string
    if (fgets(s, sizeof(s), stdin) == NULL) {
        s[0] = '\0';
    }

    // Remove trailing newline if any
    int len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
        len--;
    }

    for (int i = 0; i < len; i++) {
        // invalid character check
        if (s[i] != '0' && s[i] != '1') {
            flag = 1;
            break;
        }

        // if '0' is not followed by '1'
        if (s[i] == '0') {
            if (i == len - 1 || s[i + 1] != '1') {
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