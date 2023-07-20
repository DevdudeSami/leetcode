#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
	static bool is_palindrome(string s) {
		auto size = s.length();
		if(size == 0 || size == 1) return true;
		if(s[0] == s[size - 1]) return is_palindrome(s.substr(1, size - 2));
		return false;
	}
public:
	string longestPalindrome(string s) {
		auto size = s.length();
		string longest_palindrome = "";

		for (int i = 0; i <= size; i++) {
			for (int j = i; j <= size; j++) {
				auto substr = s.substr(i, j-i);
				if (is_palindrome(substr) && substr.length() > longest_palindrome.length()) {
					longest_palindrome = substr;
				}
			}
		}
		
		return longest_palindrome;
	}
};

int main() {
	Solution sol;

	cout << sol.longestPalindrome("babad") << endl;
	cout << sol.longestPalindrome("cbbd") << endl;
	cout << sol.longestPalindrome("a") << endl;
	cout << sol.longestPalindrome("ac") << endl;
	cout << sol.longestPalindrome("bb") << endl;
	cout << sol.longestPalindrome("") << endl;
	cout << sol.longestPalindrome("abababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa") << endl;

	return 0;
}