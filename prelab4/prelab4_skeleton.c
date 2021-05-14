#include <stdio.h>
#include <string.h>

#define MAX_SKATERS 20

typedef  struct
{
    //your code comes here
}skater_t;

double calculateAverageScore(const skater_t *skaterp);
int scanSkater(FILE *filep, skater_t *skaterp);
int loadSkaters(skater_t skaters[]);
void printSkater(const skater_t *skaterp);
int findPrintWinner(skater_t skaters[], int numOfSkaters);

int main(void)
{
    skater_t skaters[MAX_SKATERS];

    int numOfSkaters;

    numOfSkaters = loadSkaters(skaters);

    printf("Skaters:\n");
    for (int i = 0; i < numOfSkaters; i++)
        printSkater(&skaters[i]);

    findPrintWinner(skaters, numOfSkaters);

    return 0;
}

double calculateAverageScore(const skater_t *skaterp)
{
   //your code comes here
}

int scanSkater(FILE *infile, skater_t *skaterp)
{
     //your code comes here

}

int loadSkaters(skater_t skaters[])
{
    //your code comes here
}

void printSkater(const skater_t *skaterp)
{
     //your code comes here
}

int findPrintWinner(skater_t skaters[], int numOfSkaters)
{
     //your code comes here
}
