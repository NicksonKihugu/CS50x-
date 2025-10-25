#include <stdbool.h>
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
char candidates[MAX][50];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;
int voter_count;

// Function prototypes
bool vote(int rank, char name[50], int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
bool cycle_detection(int winner, int loser);
void lock_pairs(void);
void print_winner(void);

int main(int argc, char* argv[])
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
        strncpy(candidates[i],argv[i + 1], sizeof(candidates[i]) - 1);
        candidates[i][sizeof(candidates[i]) - 1] = '\0';
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
    printf("Number of voters: ");
    scanf("%d", &voter_count);
    getchar();

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            printf("Rank %d: ",j + 1);
            char name[50];
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';

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
bool vote(int rank, char name[50], int ranks[])
{
    for(int i = 0; i < candidate_count; i++)
    {
        if(strcmp(candidates[i], name) == 0)
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
    for(int i = 0; i < candidate_count; i++)
    {
        for(int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    pair_count = 0;
    for(int i = 0; i < candidate_count; i++)
    {
        for(int j = 0; j < candidate_count; j++)
        {
            if(i != j && preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{

    for(int i = 0; i < pair_count; i++)
    {
        for(int j = 0; j < pair_count - 1; j++)
        {
            // Calculate victory margins for current pair and next pair
            int margin1 = preferences[pairs[j].winner][pairs[j].loser];
            int margin2 = preferences[pairs[j + 1].winner][pairs[j + 1].loser];

            if(margin1 < margin2)
            {
                pair temp = pairs[j];
                pairs[j] = pairs[j + 1];
                pairs[j + 1] = temp;
            }
        }
    }
    return;
}

//Recursive function to check if adding edge winner to loser creates a cycle
bool cycle_detection(int winner, int loser)
{
    if(winner == loser)
    {
        return true;
    }
    for(int i = 0; i < candidate_count; i++)
    {
        if(locked[loser][i])
        {
            if(cycle_detection(winner, i))
            {
                return true;
            }
        }
    }
    return false;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for(int i = 0;i < pair_count; i++ )
    {
        int winner = pairs[i].winner;
        int loser = pairs[i].loser;

        if(!cycle_detection(winner, loser))
        {
            locked[winner][loser] = true;
        }
       
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    for(int i = 0; i < candidate_count; i++)
    {
       bool is_source = true;
       
       for(int j = 0; j < candidate_count; j++)
       {
        if(locked[j][i])
        {
            is_source = false;
            break;
        }
       }
       if(is_source)
       {
        printf("%s\n",candidates[i]);
       }
    }
    return;
}
