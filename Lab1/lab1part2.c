#include <stdio.h>
#include <math.h>

void readPointsFindMinMaxTotalLineLength(double *minLengthp, double *maxLengthp, double *totalLengthp)
{
     double currentX,currentY,tempX,tempY,index = 0;
     while (scanf("%lf %lf", &currentX, &currentY) != EOF)
    {
        if(index == 0) {
            tempX = currentX;
            tempY = currentY;
        }
        else if(index == 1) {
            double result = sqrt(pow(tempY-currentY,2)+pow(tempX-currentX,2));
            *minLengthp = result;
            *maxLengthp = result;
            tempX = currentX;
            tempY = currentY;
            *totalLengthp = result;
        }
        else{
            double result = sqrt(pow(tempY-currentY,2)+pow(tempX-currentX,2));
            if(*minLengthp>result)
            *minLengthp = result;
            else if(*maxLengthp<result)
            *maxLengthp = result;
            tempX = currentX;
            tempY = currentY;
            *totalLengthp += result;
        }
        index++;
    }

}

int main()
{
    double minLength, maxLength, totalLength;

    readPointsFindMinMaxTotalLineLength(&minLength, &maxLength, &totalLength);

    printf("Total length of line segments %.2f\n", totalLength);
    printf("Minimum length of line segments %.2f\n", minLength);
    printf("Maximum length of line segments %.2f\n", maxLength);

    return 0;
}
