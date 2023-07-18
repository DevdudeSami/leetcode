# Definition for singly-linked list.
class ListNode(object):
	def __init__(self, val=0, next=None):
		self.val = val
		self.next = next

	def __str__(self):
		return str(self.val) + " -> " + str(self.next)


class Solution(object):
	def addTwoNumbers(self, l1, l2):
		"""
		:type l1: ListNode
		:type l2: ListNode
		:rtype: ListNode
		"""
		resultList = None
		carry = 0
		l1Pointer = l1
		l2Pointer = l2
		resPointer = resultList
		resTail = resultList

		while l1Pointer != None:
			if l2Pointer == None:
				additionResult = l1Pointer.val + carry
				if additionResult > 9:
					resPointer = ListNode(additionResult - 10)
					carry = 1
				else:
					resPointer = ListNode(additionResult)
					carry = 0
			else:
				additionResult = l1Pointer.val + l2Pointer.val + carry
				if additionResult > 9:
					resPointer = ListNode(additionResult - 10)
					carry = 1
				else:
					resPointer = ListNode(additionResult)
					carry = 0
			l1Pointer = l1Pointer.next
			if l2Pointer != None:
				l2Pointer = l2Pointer.next
			if resTail == None:
				resTail = resPointer
				resultList = resPointer
			else:
				resTail.next = resPointer
			resTail = resPointer

		while l2Pointer != None:
			additionResult = l2Pointer.val + carry
			if additionResult > 9:
				resPointer = ListNode(additionResult - 10)
				carry = 1
			else:
				resPointer = ListNode(additionResult)
				carry = 0
			l2Pointer = l2Pointer.next
			if resTail == None:
				resTail = resPointer
				resultList = resPointer
			else:
				resTail.next = resPointer
			resTail = resPointer

		if carry == 1:
			resPointer = ListNode(1)
			resTail.next = resPointer
			resTail = resPointer

		return resultList


sol = Solution()

# l1 = ListNode(1,ListNode(1,ListNode(2,ListNode(4,ListNode(3)))))
# l2 = ListNode(2,ListNode(5,ListNode(6,ListNode(4))))

l1 = ListNode(
	9, ListNode(9, ListNode(9, ListNode(9, ListNode(9, ListNode(9, ListNode(9))))))
)
l2 = ListNode(9, ListNode(9, ListNode(9, ListNode(9))))

print(sol.addTwoNumbers(l1, l2))
