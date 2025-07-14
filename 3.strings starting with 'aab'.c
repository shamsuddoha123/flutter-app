#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int i, flag = 0;

    scanf("%s", s); // read string input

    int len = strlen(s);

    for (i = 0; i < len; i++) {
        if (s[i] != 'a' && s[i] != 'b') {
            flag = 1;
            break;
        }
    }

    if (flag == 0 && len >= 3 && s[0] == 'a' && s[1] == 'a' && s[2] == 'b') {
        printf("Accept\n");
    } else {
        printf("Reject\n");
    }

    return 0;
}