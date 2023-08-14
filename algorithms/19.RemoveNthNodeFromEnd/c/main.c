#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};
 
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *nodes[31];
    struct ListNode *cursor = head;
    int i = 0;
    while(cursor != NULL) {
        nodes[i] = cursor;
        i++; cursor = cursor->next;
    }
    nodes[i] = NULL;

    int target = i - n;
    if(target == 0) return head->next;

    nodes[target - 1]->next = nodes[target + 1];

    return head;
}

int main() {
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = NULL;

    struct ListNode *cursor = head;
    for(int i = 2; i <= 5; i++) {
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = i;
        node->next = NULL;
        cursor->next = node;
        cursor = node;
    }

    struct ListNode *result = removeNthFromEnd(head, 5);
    while(result != NULL) {
        printf("%d ", result->val);
        result = result->next;
    }
    printf("\n");

    return 0;
}