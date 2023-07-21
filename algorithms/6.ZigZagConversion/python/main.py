class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """

        if numRows == 1: return s


        size = len(s)
        climb_factor = numRows - 2
        climb_index = 0
        vertical_index = 0
        climbing = False

        buffer = [""] * numRows
        row_indices = [0] * numRows
        
        i = -1
        while i < size-1:
            i += 1
            if climbing:
                if climb_index == climb_factor:
                    climbing = False
                    climb_index = 0
                    i -= 1
                    continue
                
                row = climb_factor - climb_index
                
                buffer[row] += s[i]
                climb_index += 1
                continue
            
            if vertical_index == numRows:
                climbing = True
                vertical_index = 0
                i -= 1
                continue

            buffer[vertical_index] += s[i]
            vertical_index += 1

        result = ""
        for i in range(numRows):
            result += buffer[i]
        
        return result
        

sol = Solution()
print(sol.convert("PAYPALISHIRING", 3))
print(sol.convert("PAYPALISHIRING", 4))