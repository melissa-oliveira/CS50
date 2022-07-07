#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long numCredit;

    numCredit = get_long("Card number: ");

    int i;
    int soma = 0;

    for (i = 2; i < 17; i += 2)
    {
        long potencia = pow(10, i);
        long resto = numCredit % potencia;
        long restoFinal = resto / pow(10, (i - 1));

        int mult2 = restoFinal * 2;
        if (mult2 > 9)
        {
            int dig1 = mult2 / 10;
            int dig2 = mult2 % 10;
            soma += dig1 + dig2;
        }
        else
        {
            soma += mult2;
        }
    }

    int somaImpar = soma;

    for (i = 1; i < 17; i += 2)
    {
        long potenciaImpar = pow(10, i);
        long restoImpar = numCredit % potenciaImpar;
        long restoFinalImpar = restoImpar / pow(10, (i - 1));

        somaImpar += restoFinalImpar;
    }

    int verificar = somaImpar % 10;

    if (verificar == 0)
    {
        int verficiarBandeiraAmex = numCredit / pow(10, 13);
        int verficiarBandeiraMaster = numCredit / pow(10, 14);
        int verficiarBandeiraVisa1 = numCredit / pow(10, 12);
        int verficiarBandeiraVisa2 = numCredit / pow(10, 15);

        if (verficiarBandeiraAmex == 34 || verficiarBandeiraAmex == 37)
        {
            printf("AMEX\n");
        }
        else if (verficiarBandeiraMaster == 51 || verficiarBandeiraMaster == 52 || verficiarBandeiraMaster == 53
                 || verficiarBandeiraMaster == 54 || verficiarBandeiraMaster == 55)
        {
            printf("MASTERCARD\n");
        }
        else if (verficiarBandeiraVisa1 == 4)
        {
            printf("VISA\n");
        }
        else if (verficiarBandeiraVisa2 == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

