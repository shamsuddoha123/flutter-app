#include <stdio.h>
#include <string.h>

#define MAX_RULES 10
#define MAX_PRODUCTIONS 10
#define MAX_RHS 10
#define MAX_STACK 100
#define MAX_INPUT 100

char lhs[MAX_RULES];
char rhs[MAX_RULES][MAX_PRODUCTIONS][MAX_RHS];
int productionCount[MAX_RULES], ruleCount;

char input[MAX_INPUT];
int inputLen;

int isTerminal(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}

int parse(int pos, char stack[], int size)
{
    if (size == 0 && pos == inputLen)
        return 1;
    if (size == 0 || pos > inputLen)
        return 0;

    char top = stack[--size];

    if (isTerminal(top))
    {
        if (pos < inputLen && input[pos] == top)
            return parse(pos + 1, stack, size);
        else
            return 0;
    }

    for (int i = 0; i < ruleCount; i++)
    {
        if (lhs[i] != top)
            continue;

        for (int j = 0; j < productionCount[i]; j++)
        {
            char newStack[MAX_STACK];
            memcpy(newStack, stack, size);

            int tempSize = size;

            if (strcmp(rhs[i][j], "e") != 0)
            {
                int len = strlen(rhs[i][j]);
                for (int k = len - 1; k >= 0; k--)
                    newStack[tempSize++] = rhs[i][j][k];
            }

            if (parse(pos, newStack, tempSize))
                return 1;
        }
    }

    return 0;
}

void takeGrammarInput()
{
    printf("Enter number of production rules: ");
    scanf("%d", &ruleCount);
    getchar(); // consume newline after number

    for (int i = 0; i < ruleCount; i++)
    {
        char line[100];
        fgets(line, sizeof(line), stdin);

        int len = strlen(line);
        if (len > 0 && line[len - 1] == '\n')
            line[len - 1] = '\0';

        lhs[i] = line[0];

        int j = 0, k = 0;
        int arrow = 0;

        for (int idx = 0; line[idx] != '\0'; idx++)
        {
            if (!arrow && line[idx] == '-' && line[idx + 1] == '>')
            {
                arrow = 1;
                idx++; // skip '>'
                continue;
            }

            if (!arrow)
                continue;

            if (line[idx] == '|')
            {
                rhs[i][j][k] = '\0';
                j++;
                k = 0;
            }
            else
            {
                rhs[i][j][k++] = line[idx];
            }
        }

        rhs[i][j][k] = '\0';
        productionCount[i] = j + 1;
    }
}

int main()
{
    takeGrammarInput();

    printf("Enter input string: ");
    char str[MAX_INPUT];
    fgets(str, sizeof(str), stdin);

    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';

    strcpy(input, str);
    inputLen = strlen(input);

    char stack[MAX_STACK];
    stack[0] = lhs[0];

    if (parse(0, stack, 1))
        printf("ACCEPTED\n");
    else
        printf("REJECTED\n");

    return 0;
}