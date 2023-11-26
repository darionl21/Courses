#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// each of our text files contains 1000 words
#define LISTSIZE 1000

// values for colors and score (EXACT == right letter, right place; CLOSE == right letter, wrong place; WRONG == wrong letter)
#define EXACT 2
#define CLOSE 1
#define WRONG 0

// ANSI color codes for boxed in letters
#define GREEN "\e[38;2;255;255;255;1m\e[48;2;106;170;100;1m"
#define YELLOW "\e[38;2;255;255;255;1m\e[48;2;201;180;88;1m"
#define RED "\e[38;2;255;255;255;1m\e[48;2;220;20;60;1m"
#define RESET "\e[0;39m"

// user-defined function prototypes
string get_guess(int wordsize);
int check_word(string guess, int wordsize, int status[], string choice);
void print_word(string guess, int wordsize, int status[]);

// Error_001 de la TODO list #2
int error_001(string arg1, int argc);

int main(int argc, string argv[])
{

    // ensure proper usage
    // TODO #1
    int wordsize = 0;
    if (argc != 2)
    {
        error_001(argv[1], argc);
        return 1;
    }

    // ensure argv[1] is either 5, 6, 7, or 8 and store that value in wordsize instead
    // TODO #2
    wordsize = error_001(argv[1], argc);
    if (wordsize == 1)
    {
        return 1;
    }

    // open correct file, each file has exactly LISTSIZE words
    char wl_filename[6];
    sprintf(wl_filename, "%i.txt", wordsize);
    FILE *wordlist = fopen(wl_filename, "r");
    if (wordlist == NULL)
    {
        printf("Error opening file %s.\n", wl_filename);
        return 1;
    }

    // load word file into an array of size LISTSIZE
    char options[LISTSIZE][wordsize + 1];

    for (int i = 0; i < LISTSIZE; i++)
    {
        fscanf(wordlist, "%s", options[i]);
    }

    // pseudorandomly select a word for this game
    srand(time(NULL));
    string choice = options[rand() % LISTSIZE];

    // allow one more guess than the length of the word
    int guesses = wordsize + 1;
    bool won = false;

    // print greeting, using ANSI color codes to demonstrate
    printf(GREEN "This is WORDLE50" RESET "\n");
    printf("You have %i tries to guess the %i-letter word I'm thinking of\n", guesses, wordsize);

    // main game loop, one iteration for each guess
    for (int i = 0; i < guesses; i++)
    {
        // obtain user's guess
        string guess = get_guess(wordsize);

        // array to hold guess status, initially set to zero
        int status[wordsize];

        // set all elements of status array initially to 0, aka WRONG
        // TODO #4

        for (int i1 = 0; i1 < wordsize; i1++)
        {
            status[i1] = 0;
        }

        // Calculate score for the guess
        printf("%s\n", choice);
        int score = check_word(guess, wordsize, status, choice);

        printf("Guess %i: ", i + 1);

        // Print the guess
        print_word(guess, wordsize, status);

        // if they guessed it exactly right, set terminate loop
        if (score == EXACT * wordsize)
        {
            won = true;
            break;
        }
    }

    // Print the game's result
    // TODO #7
    if (won)
    {
        printf("You won!\n");
    }
    else
    {
        printf("Sorry but you are out of guesses! The correct answer was: %s\n", choice);
    }
    // that's all folks!
    return 0;
}

string get_guess(int wordsize)
{
    string guess = "";

    // ensure users actually provide a guess that is the correct length
    // TODO #3
    int letters;
    do
    {
        guess = get_string("Input a %i-letter word: ", wordsize);
        letters = strlen(guess);
    }
    while (letters != wordsize);
    return guess;
}

int check_word(string guess, int wordsize, int status[], string choice)
{
    int score = 0;

    // compare guess to choice and score points as appropriate, storing points in status
    // TODO #5

    // HINTS
    // iterate over each letter of the guess
    for (int i = 0; i < strlen(guess); i++)
    {

        // iterate over each letter of the choice
        for (int i1 = 0; i1 < strlen(choice); i1++)
        {
            int part_score = 0;

            // compare the current guess letter to the current choice letter
            if (guess[i] == choice[i1] && i == i1)
            {

                // if they're the same position in the word, score EXACT points (green) and break so you don't compare that letter
                // further
                part_score = EXACT;
            }

            // if it's in the word, but not the right spot, score CLOSE point (yellow)
            else if (guess[i] == choice[i1])
            {
                part_score = CLOSE;
            }

            // keep track of the total score by adding each individual letter's score from above
            if (part_score != 0)
            {
                score += part_score;
                status[i] = part_score;
            }
        }
    }
    return score;
}

void print_word(string guess, int wordsize, int status[])
{
    // print word character-for-character with correct color coding, then reset terminal font to normal
    // TODO #6
    for (int i = 0; i < wordsize; i++)
    {
        if (status[i] == EXACT)
        {
            printf(GREEN "%c" RESET, guess[i]);
        }
        else if (status[i] == CLOSE)
        {
            printf(YELLOW "%c" RESET, guess[i]);
        }
        else
        {
            printf(RED "%c" RESET, guess[i]);
        }
    }
    printf("\n");
}

// Error_001 de la TODO list #1
int error_001(string arg1, int argc)
{
    int wordsize = 1;
    for (int i = 0; i < 1; i++)
    {
        if (argc == 1)
        {
            printf("Usage: ./wordle wordsize\n");
            break;
        }
        switch (arg1[0])
        {
            case ('5'):
                wordsize = 5;
                break;
            case ('6'):
                wordsize = 6;
                break;
            case ('7'):
                wordsize = 7;
                break;
            case ('8'):
                wordsize = 8;
                break;
            default:
                printf("Error_001: Wordsize must be either 5, 6, 7 or 8\n");
                break;
        }
    }
    return wordsize;
}
