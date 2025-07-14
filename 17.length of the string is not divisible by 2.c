#include <stdio.h>
#include <string.h>

int main()
{
    char s[105];
    int flag = 0;

    scanf("%s", s);

    int len = strlen(s);

    // Check for invalid characters
    for (int i = 0; i < len; i++) {
        if (s[i] != 'a' && s[i] != 'b') {
            flag = 1; // Invalid character
            break;
        }
    }

    // Accept if length is odd (not divisible by 2)
    if (flag == 0 && (len % 2 != 0))
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}