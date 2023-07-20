class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        size = len(s)
        longest_palindrome = ""
    
        def is_palindrome(candidate):
            cand_size = len(candidate)
            if cand_size == 0 or cand_size == 1: return True
            if candidate[0] == candidate[-1]:
                return is_palindrome(candidate[1:-1])
            return False

        for i in range(size+1):
            for j in range(i, size+1):
                substr = s[i:j]
                if is_palindrome(substr) and len(substr) > len(longest_palindrome):
                    longest_palindrome = substr
                
        return longest_palindrome

    

if __name__ == "__main__":
    sol = Solution()
    print(sol.longestPalindrome("aaaaa"))
    print(sol.longestPalindrome("ababab"))
    print(sol.longestPalindrome("abababa"))
    print(sol.longestPalindrome(""))
    print(sol.longestPalindrome("a"))
    print(sol.longestPalindrome("ab"))
    print(sol.longestPalindrome("abc"))
    print(sol.longestPalindrome("abba"))
    print(sol.longestPalindrome("abbaa"))
    print(sol.longestPalindrome("abbaab"))
    print(sol.longestPalindrome("cackaaaaaak"))
    print(sol.longestPalindrome("abcdbbfcba"))
    print(sol.longestPalindrome("abababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa"))
