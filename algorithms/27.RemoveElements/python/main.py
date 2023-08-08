class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        i = 0
        while(i < len(nums)):
            if nums[i] == val: nums.remove(nums[i])
            else: i += 1
        
        return i
    
if __name__ == '__main__':
    sol = Solution()
    print(sol.removeElement([3,2,2,3], 3))
    print(sol.removeElement([0,1,2,2,3,0,4,2], 2))
    