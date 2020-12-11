#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef char* string;

char todo[MAX][MAX];

bool catch22(int a, string c);

int main(void)
{
    int n;
    do
    {
        printf("Things to do: ");
        scanf("%i", &n);
    }
    while (n < 0);
    
    if (n > MAX)
    {
        printf("Try again!\n");
        return 1;
    }
    
    if (n <= 0)
    {
        printf("You're a free man!\n");
        return 0;
    }
    
    for (int i = 0; i < n; i++)
    {
        char temp;
        printf("To-do %i: ", i + 1);
        scanf("%c",&temp);
        scanf("%[^\n]s", todo[i]);
    }
    
    string zero = "Done!";
    
    do
    {
        int f;
        printf("Done with: ");
        scanf("%i", &f);
        f = f - 1;
        strcpy(todo[f], zero);
        for (int y = 0; y < n; y++)
        {
            printf("To-do %i: %s\n", y + 1, todo[y]);
        }
    }
    while (catch22(n, zero) == false);
    
    if (catch22(n, zero) == true)
    {
        printf("All done buddy! Go have some fun!\n");
        return 0;
    }

    
}

bool catch22(int a, string c)
{
    for (int i = 0; i < a; i++)
    {
        if (strcmp(todo[i], c) == 0)
        {
            
        }
        else if (strcmp(todo[i], c) != 0)
        {
            return false;
        }
    }
    return true;
}