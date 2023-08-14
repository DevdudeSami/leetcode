class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        if head == None: return None
        nodes = []
        cursor = head
        i = 0
        while cursor != None:
            nodes.append(cursor)
            i += 1
            cursor = cursor.next
        nodes.append(None)

        t = i - n
        if t == 0: return head.next
        nodes[t-1].next = nodes[t+1]

        return head

if __name__ == '__main__':
  s = Solution()
  head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
  head = s.removeNthFromEnd(head, 2)
  while head != None:
    print(head.val)
    head = head.next
                      