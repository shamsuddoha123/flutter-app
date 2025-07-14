#include <stdio.h>
#include <string.h>

int main()
{
    char s[105];
    int flag = 0;

    // Read entire input line (supports empty string)
    if (fgets(s, sizeof(s), stdin) == NULL) {
        s[0] = '\0'; // If input fails, treat as empty string
    }

    // Remove newline if present
    int len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
        len--;
    }

    // Check if length is odd
    if (len % 2 != 0) {
        flag = 1;
    }

    // Check for invalid characters
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