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

int main(int argc, char *argv[])
{
    if(argc <= 1 || argc > CANDIDATES_MAX)
    {
        printf ("Usage: ./plurality <candidate1> .. <candidate9>\n");
        return EXIT_FAILURE;
    }

    const int candidate_count = argc - 1;

    struct Candidate candidate[CANDIDATES_MAX];

    // Save candidates into structure
    for (int i = 0; i < candidate_count; i++)
    {
        strcpy(candidate[i].Name, argv[i + 1]);
        printf ("Candidate %i: %s\n", i, candidate[i].Name);
    }
    

}