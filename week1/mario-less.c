#include <stdio.h>
#include <cs50.h>

int main(void)
{

    int n;

    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    int i, j, k = 0;

    for (i = 0; i < n; i++)
    {
        k++;

        for (j = 0; j < (n - k); j++)
        {
            printf(" ");
        }

        for (j = 0; j < k; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}
