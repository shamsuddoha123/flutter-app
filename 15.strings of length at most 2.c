#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    int flag = 0;

    // Read full line including empty input
    fgets(s, sizeof(s), stdin);

    // Remove newline character if present
    int len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
        len--;
    }

    // Check length at most 2
    if (len > 2) {
        flag = 1;
    }

    // Check all chars are 'a' or 'b'
    for (int i = 0; i < len; i++) {
        if (s[i] != 'a' && s[i] != 'b') {
            flag = 1;
            break;
        }
    }

    if (flag == 0)
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}