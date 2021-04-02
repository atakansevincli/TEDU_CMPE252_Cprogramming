#include <stdio.h>
#include <math.h>

/*
pre-conditions
n is greater than 1 (n > 1)
maxVal is positive (maxVal > 0)
minVal is positive (minVal > 0)
maxVal is greater than or equal to minVal (maxVal >= minVal)
*/
void printPowersInRange(int n, int p, int minVal, int maxVal)
{
    int powerOfn = pow(n,p);
    
    if(powerOfn < minVal) {
        printPowersInRange(n,p+1,minVal,maxVal);
    }
    else if(powerOfn > maxVal) {
        return;
    }
    else{
        
        printf("%d\n",powerOfn);
        p++;
        printPowersInRange(n,p,minVal,maxVal);
    }
}

int main()
{
    int number;
    int minVal, maxVal;

    printf("Enter number> ");
    scanf("%d", &number);
    printf("Enter minimum value> ");
    scanf("%d", &minVal);
    printf("Enter maximum value> ");
    scanf("%d", &maxVal);

    printPowersInRange(number, 0, minVal, maxVal);

    return 0;
}