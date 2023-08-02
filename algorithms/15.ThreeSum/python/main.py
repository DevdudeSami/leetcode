class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        n = len(nums)
        nums.sort()
            
        result = []
        for i in range(0,n):
            if i > 0 and nums[i] == nums[i-1]: continue

            start = i+1
            end = n-1
            while start < end:
                if nums[start] + nums[end] == -nums[i]:
                    result.append([nums[start], nums[end], nums[i]])
                    while start < end and nums[start] == nums[start + 1]: start += 1
                    while start < end and nums[end] == nums[end - 1]: end -= 1
                    start += 1
                    end -= 1
                elif nums[start] + nums[end] > -nums[i]:
                    end -= 1
                else:
                    start += 1

        return result
				

sol = Solution()
print(sol.threeSum([-1, 0, 1, 2, -1, -4]))
print(sol.threeSum([0,0,0,0]))
print(sol.threeSum([-2,0,0,2,2]))
print(sol.threeSum([-2,0,1,1,2]))
print(sol.threeSum([-2,0,0,2,2]))
