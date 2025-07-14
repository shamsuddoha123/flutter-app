#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    int i = 0, countA = 0, countB = 0;

    printf("Enter a string: \n");
    scanf("%s", s);

    int len = strlen(s);

    while (s[i] == 'a')//ei loop ta always agei dite hobe
    {
        countA++;
        i++;
    }

    while (s[i] == 'b')// eta always porei dite hobe
    {
        countB++;
        i++;
    }
    
    if (i == len && countA == countB && countA > 0)
    {
        printf("Accepted\n");
    }
    else
    {
        printf("Rejected\n");
    }

    return 0;
}