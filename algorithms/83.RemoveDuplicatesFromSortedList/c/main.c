#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    // Elements only need to be checked against previous
    if(head == NULL || head->next == NULL) return head;
    while(head->val == head->next->val) {
        struct ListNode *next = head->next;
        // delete next
        head->next = next->next;
        if(head->next == NULL) break;
    }
    head->next = deleteDuplicates(head->next);
    return head;
}

int main() {
		struct ListNode *head = malloc(sizeof(struct ListNode));
		head->val = 1;
		head->next = malloc(sizeof(struct ListNode));
		head->next->val = 1;
		head->next->next = malloc(sizeof(struct ListNode));
		head->next->next->val = 2;
		head->next->next->next = malloc(sizeof(struct ListNode));
		head->next->next->next->val = 3;
		head->next->next->next->next = malloc(sizeof(struct ListNode));
		head->next->next->next->next->val = 3;
		head->next->next->next->next->next = NULL;
		struct ListNode *result = deleteDuplicates(head);
		while(result != NULL) {
				printf("%d ", result->val);
				result = result->next;
		}
		printf("\n");
		return 0;
}