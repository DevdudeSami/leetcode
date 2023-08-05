#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;

    struct ListNode *p1 = list1;
    struct ListNode *p2 = list2;

    struct ListNode *res;
    if(p1->val > p2->val) {
        res = p2;
        p2 = p2->next;
    } else {
        res = p1;
        p1 = p1->next;
    }
    struct ListNode *resTail = res;

    while(p1 != NULL || p2 != NULL) {
        if(p1 == NULL) {
            resTail->next = p2;
            break;
        } else if(p2 == NULL) {
            resTail->next = p1;
            break;
        }

        if(p1->val > p2->val) {
            resTail->next = p2;
            p2 = p2->next;
        } else {
            resTail->next = p1;
            p1 = p1->next;
        }

        resTail = resTail->next;
    }

    return res;
}

int main() {
		struct ListNode l1[3];
		l1[0].val = 1;
		l1[0].next = &l1[1];
		l1[1].val = 2;
		l1[1].next = &l1[2];
		l1[2].val = 4;
		l1[2].next = NULL;

		struct ListNode l2[3];
		l2[0].val = 1;
		l2[0].next = &l2[1];
		l2[1].val = 3;
		l2[1].next = &l2[2];
		l2[2].val = 4;
		l2[2].next = NULL;

		struct ListNode *res = mergeTwoLists(l1, l2);
		while(res != NULL) {
				printf("%d ", res->val);
				res = res->next;
		}
		printf("\n");

		return 0;
}