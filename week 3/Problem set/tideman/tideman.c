#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool temciclo(int winner, int loser);
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for (int l = 0; l < candidate_count; l++)
    {
        for (int c = l + 1; c < candidate_count; c++)
        {
            preferences[ranks[l]][ranks[c]] += 1;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    for (int l = 0; l < candidate_count; l++)
    {
        for (int c = l + 1; c < candidate_count; c++)
        {
            if (preferences[l][c] > preferences[c][l])
            {
                pair_count++;
                pairs[pair_count - 1].winner = l;
                pairs[pair_count - 1].loser = c;
            }
            else if (preferences[l][c] < preferences[c][l])
            {
                pair_count++;
                pairs[pair_count - 1].winner = c;
                pairs[pair_count - 1].loser = l;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    int swapcounter = -1;
    do
    {
        swapcounter = 0;
        for (int i = 0; i < pair_count - 1; i++)
        {
            if ((preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner]) <
                (preferences[pairs[i + 1].winner][pairs[i + 1].loser] - preferences[pairs[i + 1].loser][pairs[i + 1].winner]))
            {
                swapcounter++;
                pair buffer = pairs[i];
                pairs[i] = pairs[i + 1];
                pairs[i + 1] = buffer;
            }
        }
    }
    while (swapcounter != 0);
    return;
}

bool temciclo(int winner, int loser)
{
    // TODO
    if (locked[loser][winner])
    {
        return true;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if ((locked[loser][i]) && (temciclo(winner, i)))
            return true;
    }
    return false;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    for (int i = 0; i < pair_count; i++)
    {
        if (!temciclo(pairs[i].winner, pairs[i].loser))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        int cont = 0;
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i])
            {
                cont++;
            }
        }
        if (cont == 0)
        {
            printf("%s\n", candidates[i]);
            return;
        }
    }
    return;
}
