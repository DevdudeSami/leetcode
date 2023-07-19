class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        m = len(nums1)
        n = len(nums2)
        index1 = -1
        index2 = -1

        even = (m + n) % 2 == 0

        # empty case
        if m == 0:
            return float(nums2[n//2 - 1] + nums2[n//2]) / 2 if even else nums2[n//2]
        if n == 0:
            return float(nums1[m//2 - 1] + nums1[m//2]) / 2 if even else nums1[m//2]

        # if m+n is even, the two elements needed are at (m+n)/2 - 1 and (m+n)/2
        # if m+n is odd, the element needed is at (m+n+1)/2, in the merged array

        val1 = 0
        val2 = 0

        for i in range(((m+n)//2 if even else (m+n+1)//2) + 1):
            val2 = val1
            if (index2 == n-1) or index1 < m-1 and nums1[index1+1] <= nums2[index2+1 if index2 < n-1 else index2]:
                index1 += 1
                val1 = nums1[index1]
            else:
                index2 += 1 if index2 < n-1 else index2
                val1 = nums2[index2]

        return float(val1 + val2) / 2 if even else val2

sol = Solution()
print(sol.findMedianSortedArrays([1,2], [3,4]) == 2.5)
print(sol.findMedianSortedArrays([1,3], [2]) == 2)
print(sol.findMedianSortedArrays([1], [3,4]) == 3)
print(sol.findMedianSortedArrays([1,2,3], [4,5]) == 3)
print(sol.findMedianSortedArrays([0,0], [0,0]) == 0)
print(sol.findMedianSortedArrays([3,4], []) == 3.5)
print(sol.findMedianSortedArrays([-1,3],[1,2]) == 1.5)
print(sol.findMedianSortedArrays([1,2],[-1,3]) == 1.5)
print(sol.findMedianSortedArrays([100001], [100000]))
print(sol.findMedianSortedArrays([100000], [100001]))