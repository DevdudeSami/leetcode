class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        count = len(strs)
        sizes = []
        for s in strs: sizes.append(len(s))

        result = ""

        for i in range(sizes[0]):
            breaking = False
            for j in range(count):
                if i >= sizes[j]:
                    breaking = True
                    break
                if(strs[0][i] != strs[j][i]):
                    breaking = True
                    break
            if breaking: break
            result += strs[0][i]

        return result
    

sol = Solution()
print(sol.longestCommonPrefix(["flower","flow","flight"]))
print(sol.longestCommonPrefix(["dog","racecar","car"]))
print(sol.longestCommonPrefix(["dog","dog","dog"]))
print(sol.longestCommonPrefix(["dog","dog",""]))
print(sol.longestCommonPrefix(["ab","a"]))