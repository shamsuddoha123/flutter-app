#include <stdio.h>
#include <string.h>

int main()
{
    char s[1000];
    int flag = 0;

    scanf("%s", s);

    int len = strlen(s);

    // Check for invalid characters
    for (int i = 0; i < len; i++) {
        if (s[i] != 'a' && s[i] != 'b') {
            flag = 1;
            break;
        }
    }

    // Check if string has at least 2 characters and 2nd is 'a'
    if (flag == 0 && len >= 2 && s[1] == 'a')
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}