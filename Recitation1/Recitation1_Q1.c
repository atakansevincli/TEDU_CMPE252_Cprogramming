#include <stdio.h>
int celsius_at_depth(int depth) {
return 10 * depth + 20;
}

int fahrenheit(int depth) {
    return 1.8 * celsius_at_depth(depth) + 32;
}


int main()
{
    int depth;
    printf("Enter  the depth\n");
    scanf("%d",&depth);
    printf("Celsius degree %.2f\n",(float)celsius_at_depth(depth));
    printf("Fahrenheit %.2f\n",(float)fahrenheit(depth));
    return 0;
}
