#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    int i;
    int flag = 0;
    int found = 0;

    scanf("%s", s);

    for (i = 0; i < strlen(s); i++) {
        if (s[i] != 'a' && s[i] != 'b') {
            flag = 1;
            break;
        }
    }

    if (flag == 0 && s[0] != s[strlen(s) - 1]) {
        found = 1;
    }

    if (flag == 0 && found == 1)
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}