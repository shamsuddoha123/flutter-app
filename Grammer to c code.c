#include <stdio.h>
#include <string.h>

#define MAX_RULES 10
#define MAX_PRODUCTIONS 10
#define MAX_RHS 10
#define MAX_STACK 100
#define MAX_INPUT 100

char lhs[MAX_RULES];
char rhs[MAX_RULES][MAX_PRODUCTIONS][MAX_RHS];
int productionCount[MAX_RULES];
int ruleCount;

char input[MAX_INPUT];
int inputLen;

char stack[MAX_STACK];
int top;

void initStack()
{
    top = -1;
}

int isEmpty()
{
    return top == -1;
}

void push(char c)
{
    if (top < MAX_STACK - 1)
    {
        stack[++top] = c;
    }
}

char pop()
{
    if (!isEmpty())
    {
        return stack[top--];
    }
    return '\0';
}

int isTerminal(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}

int parse(int pos, char currStack[], int currTop)
{
    if (currTop == -1 && pos == inputLen)
        return 1;
    if (currTop == -1 || pos > inputLen)
        return 0;

    char topChar = currStack[currTop];
    currTop--;

    if (isTerminal(topChar))
    {
        if (pos < inputLen && topChar == input[pos])
        {
            return parse(pos + 1, currStack, currTop);
        }
        else
        {
            return 0;
        }
    }

    int i, j, k;
    for (i = 0; i < ruleCount; i++)
    {
        if (lhs[i] == topChar)
        {
            for (j = 0; j < productionCount[i]; j++)
            {
                char newStack[MAX_STACK];
                int newTop = currTop;
                for (k = 0; k <= newTop; k++)
                    newStack[k] = currStack[k];

                if (strcmp(rhs[i][j], "e") == 0)
                {
                    if (parse(pos, newStack, newTop))
                        return 1;
                }
                else
                {
                    int len = strlen(rhs[i][j]);
                    for (k = len - 1; k >= 0; k--)
                    {
                        if (newTop < MAX_STACK - 1)
                        {
                            newStack[++newTop] = rhs[i][j][k];
                        }
                    }
                    if (parse(pos, newStack, newTop))
                        return 1;
                }
            }
        }
    }
    return 0;
}

void takeGrammarInput()
{
    printf("Enter number of production rules: ");
    scanf("%d", &ruleCount);
    getchar(); // consume newline after number input

    for (int i = 0; i < ruleCount; i++)
    {
        char line[100];
        fgets(line, sizeof(line), stdin);
        int len = strlen(line);
        if (len > 0 && line[len - 1] == '\n')
            line[len - 1] = '\0';

        lhs[i] = line[0];
        productionCount[i] = 0;

        int arrow = 0, p = 0, c = 0;
        for (int j = 0; line[j] != '\0'; j++)
        {
            if (line[j] == '-' && line[j + 1] == '>')
            {
                arrow = 1;
                j++;
                continue;
            }
            if (!arrow)
                continue;

            if (line[j] == '|')
            {
                rhs[i][p][c] = '\0';
                p++;
                c = 0;
            }
            else
            {
                rhs[i][p][c++] = line[j];
            }
        }
        rhs[i][p][c] = '\0';
        productionCount[i] = p + 1;
    }
}

int main()
{
    takeGrammarInput();

    printf("Enter input string: ");
    fgets(input, sizeof(input), stdin);

    int len = strlen(input);
    if (len > 0 && input[len - 1] == '\n')
    {
        input[len - 1] = '\0';
        len--;
    }
    inputLen = len;

    initStack();
    push(lhs[0]);

    int result = parse(0, stack, top);

    if (result)
        printf("ACCEPTED\n");
    else
        printf("REJECTED\n");

    return 0;
}