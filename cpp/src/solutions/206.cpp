#ifdef DEBUG

#include <ListNodeG.hpp>
typedef ListNodeG<int> ListNode;

#endif

class Solution {
 public:
  ListNode *reverseList(ListNode *head) {
    ListNode *prev = nullptr;
    ListNode *curr = head;
    ListNode *next = nullptr;

    while (curr) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }
};

#ifdef DEBUG

REGISTER_TEST(example0) {
  ListNode *head = nullptr;
  ListNode *groundTruth = nullptr;
  return ListNode::listsEq(Solution().reverseList(head), groundTruth);
}
REGISTER_TEST(example1) {
  ListNode *head = ListNode::vectorToListNode({1, 2, 3, 4, 5});
  ListNode *groundTruth = ListNode::vectorToListNode({5, 4, 3, 2, 1});
  return ListNode::listsEq(Solution().reverseList(head), groundTruth);
}

#endif