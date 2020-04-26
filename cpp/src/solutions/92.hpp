#ifdef DEBUG
#include "ListNodeG.hpp"
typedef ListNodeG<int> ListNode;
#endif
class Solution {
 public:
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (m == n) {
      return head;
    }
    ListNode* dummy_head = new ListNode(0);
    dummy_head->next = head;
    ListNode* curr = dummy_head;
    int i = 1;
    for (i = 1; i < m; i++) {
      curr = curr->next;
    }
    ListNode* pre_reserve_head = curr;
    curr = curr->next;
    ListNode* reserve_head = curr;
    ListNode* prev = curr;
    ListNode* next = curr->next;
    curr = curr->next;

    for (i = m + 1; i < n; i++) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    next = curr->next;
    ListNode* reserve_tail = curr;
    reserve_tail->next = prev;
    ListNode* post_reserve_tail = next;
    pre_reserve_head->next = reserve_tail;
    reserve_head->next = post_reserve_tail;

    ListNode* ret = dummy_head->next;
    dummy_head->next = nullptr;
    delete dummy_head;
    return ret;
  }
};

#ifdef DEBUG
REGISTER_TEST(sample1) {
  ListNode* head = ListNode::vectorToListNode({1, 2, 3, 4, 5});
  int m = 2, n = 4;
  ListNode* groundTruth = ListNode::vectorToListNode({1, 4, 3, 2, 5});
  ListNode* ret = Solution().reverseBetween(head, m, n);
  return ListNode::listsEq(ret, groundTruth);
}
REGISTER_TEST(sample2) {
  ListNode* head = ListNode::vectorToListNode({1, 2, 3, 4, 5});
  int m = 1, n = 5;
  ListNode* groundTruth = ListNode::vectorToListNode({5, 4, 3, 2, 1});
  ListNode* ret = Solution().reverseBetween(head, m, n);
  return ListNode::listsEq(ret, groundTruth);
}
#endif