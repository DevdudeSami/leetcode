#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head){
  if(head == NULL) return NULL;
  if(head->next == NULL) return head;
  
  struct ListNode* new_head = head->next;
  head->next = swapPairs(new_head->next);
  new_head->next = head;

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
  head->next->next->next->next = NULL;

  struct ListNode* new_head = swapPairs(head);
  while(new_head != NULL) {
    printf("%d ", new_head->val);
    new_head = new_head->next;
  }
  printf("\n");
  return 0;
}