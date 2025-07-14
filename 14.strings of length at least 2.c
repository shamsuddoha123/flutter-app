#include <stdio.h>
#include <string.h>

int main()
{
    char s[105];
    int flag = 0;

    scanf("%s", s);

    if (strlen(s) < 2) {
        flag = 1;
    }

    for (int i = 0; i < strlen(s); i++) {
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