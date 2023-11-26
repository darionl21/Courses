// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int replace(string word);

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Word required\n");
    }
    else
    {
    for (int i = 1; i < argc; i++)
    {
        replace(argv[i]);
    }
    }
}

int replace(string word)
{
    for (int i = 0; i < strlen(word); i++)
    {
        switch (word[i])
        {
            case ('a'):
                word[i] = '4';
                break;
            case ('e'):
                word[i] = '3';
                break;
            case ('i'):
                word[i] = '1';
                break;
            case ('o'):
                word[i] = '0';
                break;
        }
    }
    return printf("%s\n", word);
}