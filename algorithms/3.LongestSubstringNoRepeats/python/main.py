class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        count = len(s)
        substring = ""
        longest_substring = ""
        charIndexMap = {}

        for i in range(count):
            if s[i] in substring:
                if len(substring) > len(longest_substring):
                   longest_substring = substring 
                substring = s[charIndexMap[s[i]]:i]
                charIndexMap[s[i]] = i
            else:
                charIndexMap[s[i]] = i
                substring += s[i]
        if len(substring) > len(longest_substring):
            longest_substring = substring
        return len(longest_substring)
    
sol = Solution()
print(sol.lengthOfLongestSubstring("aab"))