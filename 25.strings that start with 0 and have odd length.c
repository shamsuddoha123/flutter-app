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
        if (s[i] != '0' && s[i] != '1') {
            flag = 1;
            break;
        }
    }

    // Check if starts with '0' and length is odd
    if (flag == 0 && s[0] == '0' && (len % 2 == 1))
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}