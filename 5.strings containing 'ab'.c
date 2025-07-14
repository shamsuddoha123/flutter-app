#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    int i;
    int flag = 0;
    int found = 0;

    scanf("%s", s);  // read string without spaces

    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] != 'a' && s[i] != 'b') {
            flag = 1;
            break;
        }
    }

    for (i = 0; s[i+1] != '\0'; i++) {
        if (s[i] == 'a' && s[i+1] == 'b') {
            found = 1;
            break;
        }
    }

    if (flag == 0 && found == 1)
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}