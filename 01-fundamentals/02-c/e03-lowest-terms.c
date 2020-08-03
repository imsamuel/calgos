// Implement a procedure to reduce a given fraction to lowest terms, using a
// struct fraction { int numerator; int denominator; }.

#include <assert.h>  // assert
#include <stdio.h>   // printf, scanf

struct Fraction lowest(const struct Fraction* f);
int gcd(int u, int v);
void swap(int* a, int* b);

// A simple attempt to model a fraction.
struct Fraction {
    int numer;
    int denom;
};

int main(void) {
    struct Fraction f = {
        numer : 178468,
        denom : 267702
    };
    struct Fraction l = lowest(&f);
    assert(l.numer == 2);
    assert(l.denom == 3);
}

// Return the lowest term of a fraction.
struct Fraction lowest(const struct Fraction* f) {
    int d = gcd(f->numer, f->denom);
    struct Fraction l = {
        numer : (f->numer) / d,
        denom : (f->denom) / d
    };
    return (struct Fraction){numer : (f->numer) / d, denom : (f->denom) / d};
}

// Return the greatest common divisor of two integers.
int gcd(int u, int v) {
    while (u > 0) {
        if (u < v) {
            swap(&u, &v);
        }
        u -= v;
    }
    return v;
}

// Swap the values of two integers.
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}