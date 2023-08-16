#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int divide(int dividend, int divisor){
    bool edge_case = false;

    if(divisor == INT_MIN) {
        return dividend == INT_MIN ? 1 : 0;
    }
    if(dividend == INT_MIN) {
        dividend += 1;
        edge_case = true;
    }

    int abs_dividend = dividend > 0 ? dividend : -dividend;
    int abs_divisor = divisor > 0 ? divisor : -divisor;

    int result_sign = 
        dividend < 0 && divisor < 0 ? 1 :
        dividend < 0 || divisor < 0 ? -1 : 1;

    if(abs_divisor == 1) return result_sign == 1 ? abs_dividend : -abs_dividend + (edge_case ? -1 : 0);

    int quotient = 0;
    while(abs_dividend >= abs_divisor) {
        abs_dividend -= abs_divisor;
        if(edge_case) {
            abs_dividend += 1;
            edge_case = false;
        }
        if(quotient > INT_MAX-1) return result_sign == 1 ? INT_MAX : INT_MIN;
        quotient++;
    }

    return result_sign == 1 ? quotient : -quotient;
}

int main() {
		printf("%d\n", divide(10, 3));
		printf("%d\n", divide(7, -3));
		printf("%d\n", divide(0, 1));
		printf("%d\n", divide(1, 1));
		printf("%d\n", divide(-1, 1));
		printf("%d\n", divide(-1, -1));
		printf("%d\n", divide(2147483647, 1));
		printf("%d\n", divide(-2147483648, 1));
		printf("%d\n", divide(-2147483648, -1));
		printf("%d\n", divide(-2147483648, 2));
		printf("%d\n", divide(-2147483648, -2));
		printf("%d\n", divide(-2147483648, 3));
		printf("%d\n", divide(-2147483648, -3));
		printf("%d\n", divide(-2147483648, 10));
		printf("%d\n", divide(-2147483648, -10));
		printf("%d\n", divide(-2147483648, 2147483647));
		printf("%d\n", divide(-2147483648, -2147483648));
		printf("%d\n", divide(2147483647, 2147483647));
		printf("%d\n", divide(2147483647, -2147483648));
		printf("%d\n", divide(-2147483648, 2147483647));
		printf("%d\n", divide(-2147483648, -2147483648));
		return 0;
}