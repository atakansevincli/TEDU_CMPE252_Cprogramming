#include <stdio.h>

void readPointsFindBoundingBox(double *bottomLeftX, double *bottomLeftY, double *widthp, double *heightp)
{
    double X,Y,Xmax,Ymax;
    int isFirst = 0;

    while (scanf("%lf %lf", &X, &Y) != EOF)
    {
        if (!isFirst)
        {
            *bottomLeftX = X;
            *bottomLeftY = Y;
            Xmax = X;
            Ymax = Y;
            isFirst++;
        }
        else
        {

            if (X < *bottomLeftX)
            {
                *bottomLeftX = X;
            }
            if (Y < *bottomLeftY)
            {
                *bottomLeftY = Y;
            }
            if (X > Xmax)
            {
                Xmax = X;
            }
            if (Y > Ymax)
            {
                Ymax = Y;
            }
        }
        
        *widthp  = Xmax - *bottomLeftX;
        *heightp = Ymax - *bottomLeftY;
    }
}
int main()
{
    double bottomLeftX, bottomLeftY, width, height;

    readPointsFindBoundingBox(&bottomLeftX, &bottomLeftY, &width, &height);

    printf("Bounding box\n");
    printf("Bottom-left corner: (%.2f %.2f)\n", bottomLeftX, bottomLeftY);
    printf("Width: %.2f\n", width);
    printf("Height: %.2f\n", height);

    return 0;
}
