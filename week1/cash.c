#include <stdio.h>
#include <cs50.h>
#include <math.h>

int get_cents();
int calculate_quarters(int a);
int calculate_dimes(int a);
int calculate_nickels(int a);
int calculate_pennies(int a);


int main(void)
{
    int n;
    int i = 0;

    n = get_cents();


    while (n >= 25)
    {
        i += calculate_quarters(n);
        n -= 25 * calculate_quarters(n);
    }

    while (n >= 10)
    {
        i += calculate_dimes(n);
        n -= 10 * calculate_dimes(n);
    }

    while (n >= 5)
    {
        i += calculate_nickels(n);
        n -= 5 * calculate_nickels(n);
    }

    while (n >= 1)
    {
        i += calculate_pennies(n);
        n -= 1 * calculate_pennies(n);
    }

    printf("%i\n", i);

}

//functions

int get_cents()
{
    int a;

    do
    {
        a = get_int("Count value: ");
    }
    while (a < 0);

    return a;
}

int calculate_quarters(int a)
{
    int b = 0;

    while (a >= 25)
    {
        b++;
        a -= 25;
    }

    return b;
}

int calculate_dimes(int a)
{
    int b = 0;

    while (a >= 10)
    {
        b++;
        a -= 10;
    }

    return b;
}

int calculate_nickels(int a)
{
    int b = 0;

    while (a >= 5)
    {
        b++;
        a -= 5;
    }

    return b;
}

int calculate_pennies(int a)
{
    int b = 0;

    while (a >= 1)
    {
        b++;
        a -= 1;
    }

    return b;
}
