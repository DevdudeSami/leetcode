class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        def inv(c):
            return {'{':'}', '}':'{', '(':')', ')':'(', '[':']', ']':'['}[c]

        l = []
        for c in s:
            if c in ['{','[','(']:
                l.append(c)
            else:
                if len(l) == 0: return False
                # closing, last element in l must match
                if c != inv(l[-1]): return False
                l.pop()

        # all opened must be shut
        if len(l) != 0: return False
        return True
                