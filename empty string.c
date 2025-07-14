#include <stdio.h>

int main() {
    char c;
    scanf("%c", &c);

    if (c == '\n') {
        printf("accepted\n");
    } else {
        printf("not accepted\n");
    }

    return 0;
}