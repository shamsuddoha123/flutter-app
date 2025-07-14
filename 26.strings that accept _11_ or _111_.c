#include <stdio.h>
#include <string.h>

int main()
{
    char s[105];
    int flag = 0;

    scanf("%s", s);

    // Check for invalid characters
    for (int i = 0; i < (int)strlen(s); i++) {
        if (s[i] != '0' && s[i] != '1') {
            flag = 1;
            break;
        }
    }

    // Check for exact match: "11" or "111"
    if (flag == 0 && (strcmp(s, "11") == 0 || strcmp(s, "111") == 0))
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}