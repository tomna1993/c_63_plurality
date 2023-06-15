#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANDIDATES_MAX 9
#define CHARS_MAX 30

struct Candidate
{
    char    Name[CHARS_MAX];
    int     Votes;
};

bool vote(char name[CHARS_MAX], struct Candidate candidate[CANDIDATES_MAX], int candidate_count);
int print_winner(struct Candidate candidate[], int candidate_count);

int main(int argc, char *argv[])
{
    // If no arguments, throw ERROR; check for max candidate number too
    if(argc <= 1 || argc > CANDIDATES_MAX)
    {
        printf ("Usage: ./plurality <candidate1> .. <candidate9>\n");
        return EXIT_FAILURE;
    }

    // Save number of candidates
    const int candidate_count = argc - 1;

    struct Candidate candidate[CANDIDATES_MAX];

    // Save candidates Name into structure and clear ther votes
    for (int i = 0; i < candidate_count; i++)
    {
        strcpy(candidate[i].Name, argv[i + 1]);
        candidate[i].Votes = 0;
    }
    
    const int number_of_voters = get_int("Number of voters: ");
    // Get votes from user
    int vote_count = 1;
    do
    {
        // Check if voter gave a correct candidate name and increment candidates votes
        if(vote(get_string("Vote: "), candidate, candidate_count))
        {
            vote_count++;
            continue;
        }
        
        printf ("Invalid vote!\n");
        
    } while (vote_count <= number_of_voters);

    // Print most voted candidate
    print_winner(candidate, candidate_count);

    return EXIT_SUCCESS;
}

// Check if name is in candidate structure; if yes increment its vote counter
bool vote(char name[CHARS_MAX], struct Candidate candidate[CANDIDATES_MAX], int candidate_count)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidate[i].Name, name) == 0) 
        {
            candidate[i].Votes++;
            return true;
        }
    }

    return false;
}

// Check what is the biggest vote count and print the candidates names 
// who reached the most votes
int print_winner(struct Candidate candidate[], int candidate_count)
{
    int max_votes = candidate[0].Votes;

    // Get the number of maximum votes
    for (int i = 1; i < candidate_count; i++)
    {
        if(max_votes < candidate[i].Votes)
        {
            max_votes = candidate[i].Votes;
        }
    }

    // Check which candidates reached maximum votes and print their names
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidate[i].Votes == max_votes)
        {
            printf ("%s\n", candidate[i].Name);
        }
    }

    return EXIT_SUCCESS;
}