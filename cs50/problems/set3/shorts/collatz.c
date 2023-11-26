#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name, int argc, string argv[]);
void tabulate(int argc, int votes_number);
bool print_winner(int argc, int total_votes);
int find_min(int argc);
bool is_tie(int min, int argc);
void eliminate(int min, int argc);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name, argc, argv))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }
        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate(argc, voter_count);

        // Check if election has been won
        bool won = print_winner(argc, voter_count);
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min(argc);
        bool tie = is_tie(min, argc);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min, argc);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name, int argc, string argv[])
{
    // TODO
    for (int i = 1; i < argc; i++)
    {
        int valid = strcmp(name, argv[i]);
        if (valid == 0)
        {
            preferences[voter][rank] = i - 1;
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(int argc, int votes_number)
{
    // TODO
    for (int voter = 0; voter < votes_number; voter++)
    {
        for (int rank = 0; rank < argc; rank++)
        {
            if (!candidates[preferences[voter][rank]].eliminated)
            {
                candidates[preferences[voter][rank]].votes++;
                break;
            }
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(int argc, int total_votes)
{
    // TODO
    int winner_rule = total_votes / 2;
    for (int i = 0; i < argc; i++)
    {
        if (candidates[i].votes > winner_rule)
        {
            printf("%s wins! With %i votes\n", candidates[i].name, candidates[i].votes);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(int argc)
{
    // TODO
    int min = candidates[0].votes;
    for (int i = 1; i < argc - 1; i++)
    {
        if (min > candidates[i].votes)
            min = candidates[i].votes;
    }
    return min;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min, int argc)
{
    // TODO
    for (int i = 0; i < argc - 1; i++)
    {
        if (!candidates[i].eliminated)
        {
            if (min != candidates[i].votes)
                return false;
        }
    }
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min, int argc)
{
    // TODO
    for (int i = 0; i < argc - 1; i++)
    {
        if (min == candidates[i].votes)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}
