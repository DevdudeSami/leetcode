from math import log10

class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        
        if x == 0: return True
        if x < 0: return False

        oom = int(log10(x))
        if oom == 0: return True

        first_digit = x // (10 ** oom)
        last_digit = x % 10
        if first_digit == last_digit:
            in_between_digits = x % (10 ** oom) // 10
            if in_between_digits == 0: return True
            in_between_oom = int(log10(in_between_digits))
            # for every zero digit after the first_digit, check if the digits before the last_digit are zero
            oom_diff = oom - in_between_oom
            if oom_diff > 2:
                number_of_zeros = oom_diff - 2
                if in_between_digits % (10 ** number_of_zeros) == 0:
                    in_between_digits = in_between_digits // (10 ** number_of_zeros)
                else: return False
            return self.isPalindrome(in_between_digits)
        
        return False
        


if __name__ == '__main__':
    s = Solution()
    print(s.isPalindrome(11))

		