#include <stdio.h>
#include <string.h>

int main()
{
    char s[105];
    int flag = 0;

    if (fgets(s, sizeof(s), stdin) == NULL) {
        s[0] = '\0';  // treat as empty string if input fails
    }

    // Remove trailing newline if any
    int len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
        len--;
    }

    // Check for invalid characters
    for (int i = 0; i < len; i++) {
        if (s[i] != 'a' && s[i] != 'b') {
            flag = 1;  // invalid character found
            break;
        }
    }

    // Check if it starts with 'a'
    if (flag == 0 && len > 0 && s[0] == 'a') {
        flag = 1;  // reject if starts with 'a'
    }

    if (flag == 0)
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}