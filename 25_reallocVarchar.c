#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void convrUpper(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = toupper(str[i]);
    }
}

int checker(char *str)
{
    int strlng = strlen(str), result = 0, j = 0, i;

    for (i = strlng - 1; i >= 0; i--)
    {
        if (str[i] == ')')
        {
            i--;
            while (str[i] != '(')
            {

                j++;
                if (j > 1)
                {
                    result += ((str[i] - '0') * 10);
                }
                else
                {
                    result += (str[i] - '0');
                }
                i--;
            }
            break;
        }
    }
    return result;
}

void work(char *str)
{
    convrUpper(str);
    int i;
    for (i = 5; str[i] != '\0' && str[i] != 'V'; i++)
    {
        if (str[i + 1] == 'V')
        {
            str[i + 1] = '\0';
        }
    }
    for (i = 0; str[i] != '\0'; i++)
    {
        printf("%c", str[i]);
    }
}

int main()
{
    int n = 100, i;
    char *str;
    str = (char *)calloc(n, sizeof(char));

    printf("SQL> ");
    scanf(" %[^\n]", str);

    int new = checker(str);
    char *name;

    if (new != n)
    {
        name = (char *)realloc(str, new * sizeof(char));

        if (name == NULL)
        {
            printf("Memory reallocation failed.\n");
            free(str);
            return 1;
        }
    }
    printf("\nNAME\n");
    for (i = 1; i <= new; i++)
    {
        printf("-");
    }
    printf("\n");
    work(name);
    free(name);
    return 0;
}
