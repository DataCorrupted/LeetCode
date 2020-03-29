/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *head = new ListNode(0);
    ListNode *p = l1;
    ListNode *q = l2;
    ListNode *ptr = head;
    int carry = 0;
    while (p != NULL || q != NULL) {
      int x = (p != NULL) ? p->val : 0;
      int y = (q != NULL) ? q->val : 0;
      int sum = carry + x + y;
      carry = sum / 10;
      ptr->next = new ListNode(sum % 10);
      ptr = ptr->next;
      if (p != NULL) p = p->next;
      if (q != NULL) q = q->next;
    }
    if (carry > 0) {
      ptr->next = new ListNode(carry);
    }
    return head->next;
  }
};