#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name, int argc, string argv[]);
void print_winner(int argc);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name, argc, argv))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner(argc);
}

// Update vote totals given a new vote
bool vote(string name, int argc, string argv[])
{
    // TODO
    for (int i = 0; i < argc; i++)
    {
        int n = strcmp(argv[i], name);
        if (n == 0)
        {
            candidates[i - 1].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(int argc)
{
    // TODO
    int new_array[argc];
    for (int i = 0; i < argc; i++)
    {
        for (int j = 0; j < argc - i; j++)
        {
            if (candidates[i].votes < candidates[j].votes)
                candidates[i].name = candidates[j].name;
        }
    }
    printf("%s\n", candidates[0].name);
    for (int i = 1; i < argc; i++)
    {
        if (candidates[0].votes == candidates[i].votes)
            printf("%s\n", candidates[i].name);
    }
    return;
}