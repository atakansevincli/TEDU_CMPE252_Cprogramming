#include <stdio.h>
#include <stdbool.h>

bool isDivisibleBy9(int number) {
 return ((sumOfDigits(number)%9==0) ? true : false);
}

int sumOfDigits(int number) {

 int sum = 0;
    while (number) {
    sum += number % 10 ;
    number /= 10;
    }
    return sum;
}

int main()
{
    int number;
    printf("Enter an integer:\n");
    scanf("%d",&number);
    printf("Sum of the digits: %d\n",sumOfDigits(number));
    isDivisibleBy9(number) ? printf("Divisible by 9: Yes") : printf("Divisible by 9: No");
    return 0;
}
