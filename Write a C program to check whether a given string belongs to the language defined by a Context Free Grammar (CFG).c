#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_RULES 100
#define MAX_NONTERMINALS 26
#define MAX_LEN 100

typedef struct
{
    char lhs;
    char rhs1;
    char rhs2;
    bool isTerminal;
} Rule;

Rule rules[MAX_RULES];
int ruleCount = 0;

bool table[MAX_LEN][MAX_LEN][MAX_NONTERMINALS];

int getIndex(char c)
{
    return c - 'A';
}

void addRule(char lhs, char rhs1, char rhs2, bool isTerminal)
{
    rules[ruleCount].lhs = lhs;
    rules[ruleCount].rhs1 = rhs1;
    rules[ruleCount].rhs2 = rhs2;
    rules[ruleCount].isTerminal = isTerminal;
    ruleCount++;
}

bool CYK(const char *input)
{
    int n = strlen(input);
    memset(table, false, sizeof(table));

    // Initialize table for terminals
    for (int i = 0; i < n; i++)
    {
        for (int r = 0; r < ruleCount; r++)
        {
            if (rules[r].isTerminal && rules[r].rhs1 == input[i])
            {
                table[i][i][getIndex(rules[r].lhs)] = true;
            }
        }
    }

    // CYK table filling
    for (int l = 2; l <= n; l++)
    { // length of span
        for (int i = 0; i <= n - l; i++)
        {                      // start of span
            int j = i + l - 1; // end of span
            for (int k = i; k < j; k++)
            {
                for (int r = 0; r < ruleCount; r++)
                {
                    if (!rules[r].isTerminal)
                    {
                        int B = getIndex(rules[r].rhs1);
                        int C = getIndex(rules[r].rhs2);
                        if (table[i][k][B] && table[k + 1][j][C])
                        {
                            table[i][j][getIndex(rules[r].lhs)] = true;
                        }
                    }
                }
            }
        }
    }

    return table[0][n - 1][getIndex('S')];
}

int main()
{
    int numRules;
    char line[100];

    printf("Enter number of rules: ");
    scanf("%d", &numRules);
    getchar(); // consume newline

    printf("Enter rules (e.g., S -> AB or A -> a):\n");
    for (int i = 0; i < numRules; i++)
    {
        fgets(line, sizeof(line), stdin);
        char lhs, rhs1, rhs2;
        int len = strlen(line);
        if (len > 0 && line[len - 1] == '\n')
            line[len - 1] = '\0';

        if (sscanf(line, "%c -> %c%c", &lhs, &rhs1, &rhs2) == 3)
        {
            addRule(lhs, rhs1, rhs2, false); // Non-terminal rule
        }
        else if (sscanf(line, "%c -> %c", &lhs, &rhs1) == 2)
        {
            addRule(lhs, rhs1, 0, true); // Terminal rule
        }
        else
        {
            printf("Invalid rule format!\n");
            return 1;
        }
    }

    char input[MAX_LEN];
    printf("Enter string to test: ");
    scanf("%s", input);

    if (CYK(input))
    {
        printf("✅ The string \"%s\" is **ACCEPTED** by the grammar.\n", input);
    }
    else
    {
        printf("❌ The string \"%s\" is **REJECTED** by the grammar.\n", input);
    }

    return 0;
}