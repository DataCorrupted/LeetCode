#ifdef DEBUG

#include "ListNodeG.hpp"
typedef ListNodeG<int> ListNode;
#endif

class Solution {
 public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    if (head->next == nullptr || head == nullptr) {
      return nullptr;
    }
    ListNode *pesudo_head = new ListNode(0);
    pesudo_head->next = head;

    ListNode *tail = pesudo_head;
    ListNode *prev_to_delete = pesudo_head;
    for (int i = 0; i < n; i++) {
      tail = tail->next;
    }
    while (tail->next != nullptr) {
      tail = tail->next;
      prev_to_delete = prev_to_delete->next;
    }
    prev_to_delete->next = prev_to_delete->next->next;
    head = pesudo_head->next;
    pesudo_head->next = NULL;
    delete pesudo_head;
    return head;
  }
};

#ifdef DEBUG
#include "DebugUtil.h"

REGISTER_TEST(0) {
  int n = 2;
  ListNode *head = new ListNode(
      1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
  ListNode *groundTruth =
      new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(5))));
  return ListNode::listsEq(Solution().removeNthFromEnd(head, n), groundTruth);
}
#endif