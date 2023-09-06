from math import ceil

class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        t = ceil(len(nums)/2.0)
        counts = {}
        for i in range(0,len(nums)):
            n = nums[i]
            if n in counts:
                counts[n] += 1
            else:
                counts[n] = 1
            if counts[n] == t: return n
        return 0
  
sol = Solution()
print(sol.majorityElement([1,2,3,4,5,6,7,8,9,9,9,9,9,9,9,9]))
print(sol.majorityElement([1,2,3,4,59,9,9,9,9,9,9]))
