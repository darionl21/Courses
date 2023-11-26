#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Da una lista de numeros que s eva duplicando
    int n;
    do
    {
        n = get_int("Duplication size: ");
    }
    while (n < 1);
    int array[n];
    array[0] = 1;
    printf("%i\n", array[0]);
    for (int i = 1; i < n; i++)
    {
        array[i] = array[i - 1] * 2;
        printf("%i\n", array[i]);
    }

    // Comprueba que las letras estan en orden alfabetico
    string word = get_string("Word: ");
    int length = strlen(word);
    int i1;
    for (i1 = 1; i1 < length;)
    {
        if (word[i1] > word[i1 - 1])
        {
            i1++;
        }
        else
        {
            break;
        }
    }
    if (i1 == length)
    {
        printf("Yes it is in alphabetical order\n");
    }
    else
    {
        printf("No está en orden alfabético\n");
    }

    // Te da la letra del argumento deseado, en este caso la incial
    int i3 = 0;
    for (int i2 = 1; i2 < argc; i2++)
    {
        printf("%c\n", argv[i2][i3]);
    }
}