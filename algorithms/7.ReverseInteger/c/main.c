#include <limits.h>
#include <stdio.h>

int reverse(int x){
	int reversed = 0;
	int original = x;

	if(x == INT_MIN) return 0;
	if(x < 0) original *= -1;

	while (original > 0) {
		if(reversed > INT_MAX/10 - original%10 + 1) return 0;
		reversed = reversed * 10 + original % 10;
		original /= 10;
	}

	if(x < 0) reversed *= -1;

	return reversed;
}

int main() {
	printf("%d\n", reverse(123));
	printf("%d\n", reverse(-123));
	printf("%d\n", reverse(120));
	printf("%d\n", reverse(0));
	printf("%d\n", reverse(1534236469));
	printf("%d\n", reverse(-2147483648));
	return 0;
}