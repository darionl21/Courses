#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    // TODO
    int resto;
    if (number == 1)
    {
        return false;
    }
    for (int menos = number - 1; menos > 1; menos--)
    {
        resto = number % menos;
        if (resto == 0)
        {
            return false;
        }
    }
    return true;
}
