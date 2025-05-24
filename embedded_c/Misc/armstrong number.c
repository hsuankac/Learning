#include <stdio.h>
#include <math.h>

/*
An Armstrong number (also known as a narcissistic number, 
pluperfect number, or pluperfect digital invariant) is a number that is equal to the sum of its own digits 
each raised to the power of the number of digits.
*/

int isArmstrong(int num) {
    int original = num;
    int sum = 0;
    int digits = 0;

    // Count number of digits
    int temp = num;
    while (temp > 0) {
        digits++;
        temp /= 10;
    }

    // Calculate sum of digits^digits
    temp = num;
    while (temp > 0) {
        int digit = temp % 10;
        sum += (int)(round(pow(digit, digits)));  // Fix here
        temp /= 10;
    }

    return sum == original;
}


int main()
{
    int n = 153;
    printf("153 is an armstrong number: %d\n", isArmstrong(n));
    return 0;
}