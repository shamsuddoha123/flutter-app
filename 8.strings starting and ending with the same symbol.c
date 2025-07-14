#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    int i;
    int flag = 0;
    int found = 0;

    // Read input line including empty string
    if (fgets(s, sizeof(s), stdin) == NULL) {
        // If fgets fails, consider empty string
        s[0] = '\0';
    }

    // Remove trailing newline, if any
    int len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
    s[len - 1] = '\0';
    len--;
    }

    for (i = 0; i < len; i++) {
        if (s[i] != 'a' && s[i] != 'b') {
            flag = 1;
            break;
        }
    }

    // Accept empty string or first == last char
    if (flag == 0 && (len == 0 || s[0] == s[len - 1])) {
        found = 1;
    }

    if (flag == 0 && found == 1)
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}