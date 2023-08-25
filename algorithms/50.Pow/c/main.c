#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

double myPow(double x, int n){
    if(n == 0) return 1;
    if(n == 1) return x;

    int abs_n = n;

    if(n < 0) {
        x = 1/x;
        abs_n = n == INT_MIN ? -(n+1) : -n;
    }

    // recursive call
    double halfPow = myPow(x, abs_n / 2);

    double result;
    if(abs_n % 2 == 0) result = halfPow * halfPow;
    else result = halfPow * halfPow * x;

    if(n == INT_MIN) return result * x;
    return result;
}

int main() {
    printf("%f\n", myPow(2.0, 10));
    printf("%f\n", myPow(2.1, 3));
    printf("%f\n", myPow(2.0, -2));
    printf("%f\n", myPow(2.0, -2147483648));
    return 0;
}