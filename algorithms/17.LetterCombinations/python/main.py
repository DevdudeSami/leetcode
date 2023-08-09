class Solution(object):
	def letterCombinations(self, digits):
		"""
		:type digits: str
		:rtype: List[str]
		"""
		# Each digit maps to a list of chars
		# The result is the cartesian product of the lists
		def cartesian_product(l1, l2):
			return [x+y for x in l1 for y in l2]
			
		mapping = {
			'2': ['a', 'b', 'c'],
			'3': ['d', 'e', 'f'],	
			'4': ['g', 'h', 'i'],	
			'5': ['j', 'k', 'l'],
			'6': ['m', 'n', 'o'],
			'7': ['p', 'q', 'r', 's'],
			'8': ['t', 'u', 'v'],
			'9': ['w', 'x', 'y', 'z']	
		}

		if len(digits) == 0: return []
		if len(digits) == 1: return mapping[digits[0]]

		lists = [mapping[digit] for digit in digits]
		result = lists[0]
		for i in range(1, len(lists)):
			result = cartesian_product(result, lists[i])

		return result
	
if __name__ == '__main__':
	sol = Solution()
	print(sol.letterCombinations('23'))
	print(sol.letterCombinations(''))
	print(sol.letterCombinations('2'))
	print(sol.letterCombinations('234'))


				
