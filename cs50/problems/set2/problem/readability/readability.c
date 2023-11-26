#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);

int count_words(string text);

int count_sentences(string text);

int main(int argc, string argv[])
{
    string text = get_string("Text: ");
    printf("%s\n", text);
    float letters = count_letters(text);
    float words = count_words(text);
    float sentences = count_sentences(text);
    double L = letters / words * 100;
    double S = sentences / words * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text)
{
    int letters = strlen(text);
    for (int i = 0; i < strlen(text); i++)
    {
        int a_numero = text[i];
        if ((a_numero < 97 && a_numero > 90) || a_numero < 65 || a_numero > 122)
        {
            letters--;
        }
    }
    return letters;
}

int count_words(string text)
{
    int words = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }
    return sentences;
}