#include <cs50.h>
#include <stdio.h>
void printpyramid(int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n - i; j++)
        {
            printf(" ");
        }
        for (int k = n - i; k < n; k++)
        {
            printf("#");
        }
        for (int l = n + 1; l < n + 3; l++)
        {
            printf(" ");
        }
        for (int b = n + 3; b < n + 3 + i; b++)
        {
            printf("#");
        }
        printf("\n");
    }
}
int main()
{
    int n;
    while (true)
    {
        n = get_int("Enter the Height of Box\n");
        if (n >= 1 && n <= 8)
        {
            break;
        }
    }
    n++;
    printpyramid(n);
    return 0;
}
