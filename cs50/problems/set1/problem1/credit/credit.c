#include <cs50.h>
#include <stdio.h>

bool valid(long number);
bool amex(long number);
bool mastercard(long number);
bool visa(long number);
int main(void)
{
    // Start
    long card = get_long("Number: ");
    // Answer
    if (valid(card))
    {
        if (amex(card))
        {
            printf("AMEX\n");
        }
        else if (mastercard(card))
        {
            printf("MASTERCARD\n");
        }
        else if (visa(card))
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

// Valid
bool valid(long number)
{

    // Pares
    long sumapar = 0;
    for (long i = 100; i < 100000000000000000; i = i * 100)
    {
        long a = ((number % i - number % (i / 10)) / (i / 10) * 2) % 10;
        long b = (((number % i - number % (i / 10)) / (i / 10) * 2) % 100 - a) / 10;
        sumapar = sumapar + a + b;
    }

    // Impares
    long sumaimp = 0;
    for (long i = 10; i < 100000000000000000; i = i * 100)
    {
        long c = (number % i - number % (i / 10)) / (i / 10);
        sumaimp = sumaimp + c;
    }

    // valid
    long ok = (sumapar + sumaimp) % 10;
    printf("%ld\n", ok);
    if (ok == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// AMEX
bool amex(long number)
{
    long a;
    for (long i = 100000000000000000; i > 10000000000000; i = i / 10)
    {
        a = (number % i) / (i / 100);
        if (a == 34 || a == 37)
        {
            return true;
        }
    }
    return false;
}

// MASTERCARD
bool mastercard(long number)
{
    long a;
    for (long i = 100000000000000000; i > 10000000000000; i = i / 10)
    {
        a = (number % i) / (i / 100);
        if (a == 51 || a == 52 || a == 53 || a == 54 || a == 55)
        {
            return true;
        }
    }
    return false;
}

// VISA
bool visa(long number)
{
    long a = 0;
    for (long i = 100000000000000000; i > 100000000000 && a == 0; i = i / 10)
    {
        a = ((number % i - number % (i / 10)) / (i / 10));
        printf("%ld\n", a);
        if (a == 4)
        {
            return true;
        }
    }
    return false;
}