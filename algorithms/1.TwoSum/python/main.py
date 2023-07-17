class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        count = len(nums)
        for i in range(0,count-1):
            for j in range(i+1,count):
                if nums[i] + nums[j] == target:
                    return [i,j]
        print("None found")
        return [0,0]