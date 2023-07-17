class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        numMap = {}
        count = len(nums)

        for i in range(0,count):
            diff = target - nums[i]
            if diff in numMap: # check if the difference is in the map; if so, we're done
                return [numMap[diff], i]
            numMap[nums[i]] = i # insert this num into the map
            
        print("None found")
        return [0,0]
