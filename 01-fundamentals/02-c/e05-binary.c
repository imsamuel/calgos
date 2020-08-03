// Write a function binary(int x) that prints out the binary equivalent of a
// number.

#include <math.h>   // pow, round
#include <stdio.h>  // printf, scanf

int binary(int num);

int main(void) {
    printf("enter a positive integer: ");
    int num;
    scanf("%d", &num);
    printf("the binary representation of %d is %d", num, binary(num));
    return 0;
}

// Return the binary representation of a (positive) integer.
int binary(int num) {
    int result = 0;
    for (int exponent = 0; num > 0; num /= 2, ++exponent) {
        int remainder = num % 2;
        if (remainder == 1) {
            result += round(pow(10, exponent));  // prevents truncation of fp
        }
    }
    return result;
}