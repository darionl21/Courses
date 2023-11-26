#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    // Recogida de datos de altura

    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Creacion de los bloques
    for (int i = 0; i < height; i++)
    {

        for (int k = height - 1; k > i; k--)
        {
            printf(" ");
        }
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}