#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x){
	long long reversed = 0;
	long long original = x;

	while (x > 0) {
		reversed = reversed * 10 + x % 10;
		x /= 10;
	}

	return reversed == original;
}

int main() {
	printf("%d\n", isPalindrome(121));
	printf("%d\n", isPalindrome(-121));
	printf("%d\n", isPalindrome(10));
	printf("%d\n", isPalindrome(-101));
	return 0;
}