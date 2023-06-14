#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

#define CANDIDATES_MAX 9

int main(int argc, string argv[])
{
    if(argc <= 1 || argc > CANDIDATES_MAX)
    {
        printf ("Usage: ./plurality <candidate1> .. <candidate9>\n");
        return EXIT_FAILURE;
    }
}