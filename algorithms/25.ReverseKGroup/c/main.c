#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* reverseKGroup(struct ListNode* head, int k){
    if(head == NULL || head->next == NULL) return head;

    struct ListNode* nodes[k];
    struct ListNode* cursor = head;

    for(int i = 0; i < k; i++) {
        if(cursor == NULL) return head;
        nodes[i] = cursor;
        cursor = cursor->next;
    }

    struct ListNode* new_head = nodes[k-1];
    for(int i = k-2; i >= 0; i--) {
        nodes[i+1]->next = nodes[i];
    }

    nodes[0]->next = reverseKGroup(cursor, k); // cursor now points to the start of the next group

    return new_head;
}

int main(void) {
	struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
	head->val = 1;
	head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
	head->next->val = 2;
	head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
	head->next->next->val = 3;
	head->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
	head->next->next->next->val = 4;
	head->next->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
	head->next->next->next->next->val = 5;
	head->next->next->next->next->next = NULL;

	struct ListNode* new_head = reverseKGroup(head, 3);
	while(new_head != NULL) {
		printf("%d ", new_head->val);
		new_head = new_head->next;
	}
	printf("\n");
	return 0;
}