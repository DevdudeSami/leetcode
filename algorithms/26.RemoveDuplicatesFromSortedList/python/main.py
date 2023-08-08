class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        uniques = []
        i = 0
        while(i < len(nums)):
            if nums[i] in uniques:
                nums.remove(nums[i])
            else:
                uniques.append(nums[i])
                i += 1

        return i

if __name__ == '__main__':
    sol = Solution()
    print(sol.removeDuplicates([1,1,2]))
    print(sol.removeDuplicates([0,0,1,1,1,2,2,3,3,4]))
    