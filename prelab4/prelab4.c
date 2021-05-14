#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SKATERS 20

typedef struct
{
    char name[20];
    char surname[20];
    double refereeScores[6];
    double averageScore;
} skater_t;

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
    int min = skaterp->refereeScores[0];
    int max = skaterp->refereeScores[0];
    for (int i = 0; i < 6; i++)
    {
        if (min > skaterp->refereeScores[i])
        {
            min = skaterp->refereeScores[i];
        }
        if (max < skaterp->refereeScores[i])
        {
            max = skaterp->refereeScores[i];
        }
    }
    double total = 0;
    for (int i = 0; i < 6; i++)
    {
        total += skaterp->refereeScores[i];
    }
    return ((total - max - min) / 4);
}

int scanSkater(FILE *infile, skater_t *skaterp)
{

    char buff[255];
    int c;
    if ((c = fscanf(infile, "%s", buff)) == EOF)
    {
        printf("Loading complete\n");
        return 0;
    }
    strcpy(skaterp->name, buff);
    fscanf(infile, "%s", buff);
    strcpy(skaterp->surname, buff);

    for (int i = 0; i < 6; i++)
    {
        fscanf(infile, "%s", buff);
        skaterp->refereeScores[i] = atof(buff);
    }
    skaterp->averageScore = calculateAverageScore(skaterp);
    return 1;
}

int loadSkaters(skater_t skaters[])
{
    int numOfSkaters = 0, c;
    FILE *fp;
    printf("Enter the file name to read: ");
    char filename[256];
    gets(filename);
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        return 0;
    }
    printf("Opening %s\n", filename);
    for (int i = 0; (c = scanSkater(fp, &skaters[i])) != 0; i++)
    {
        numOfSkaters++;
    }

    fclose(fp);
    printf("Closing %s\n", filename);
    return numOfSkaters;
}

void printSkater(const skater_t *skaterp)
{
    printf("%s %s %.2f\n", skaterp->name, skaterp->surname, skaterp->averageScore);
}

int findPrintWinner(skater_t skaters[], int numOfSkaters)
{
    int WinnerIndex = 0;
    for (int i = 0; i < numOfSkaters; i++)
    {
        if (skaters[WinnerIndex].averageScore < skaters[i].averageScore)
        {
            WinnerIndex = i;
        }
    }
    printf("Winner:\n");
    printSkater(&(skaters[WinnerIndex]));
    return WinnerIndex;
}