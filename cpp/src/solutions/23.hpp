/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Compare {
 public:
  bool operator()(ListNode *a, ListNode *b) { return a->val > b->val; }
};

class Solution {
 public:
  ListNode *mergeKLists(std::vector<ListNode *> &lists) {
    ListNode *pesudo_head = new ListNode(0);
    ListNode *head = pesudo_head;

    int empty_cnt = 0;
    priority_queue<ListNode *, vector<ListNode *>, Compare> heap;
    for (int i = 0; i < lists.size(); i++) {
      if (lists[i] != nullptr) {
        heap.push(lists[i]);
      } else {
        empty_cnt++;
      }
    }

    while (empty_cnt != lists.size()) {
      head->next = heap.top();
      heap.pop();
      head = head->next;
      if (head->next == nullptr) {
        empty_cnt++;
      } else {
        heap.push(head->next);
      }
    }

    ListNode *ans = pesudo_head->next;
    delete pesudo_head;
    return ans;
  }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
 * This solution should have a speed of O(nm lg m).
 * But it is not stable. We will change to another one.
 *
 */
class SolutionTLE {
 public:
  ListNode *mergeTwoLists(ListNode *a, ListNode *b) {
    if (a == nullptr) {
      return b;
    }
    if (b == nullptr) {
      return a;
    }
    if (a->val > b->val) {
      swap(a, b);
    }
    ListNode *merged_list = a;
    ListNode *prev = a;
    a = a->next;
    while (a != nullptr && b != nullptr) {
      if (a->val < b->val) {
        prev = a;
        a = a->next;
      } else {
        ListNode *insert_head = b;
        ListNode *insert_tail = b;

        while (insert_tail->next != nullptr &&
               insert_tail->next->val < a->val) {
          insert_tail = insert_tail->next;
        }

        b = insert_tail->next;

        prev->next = insert_head;
        insert_tail->next = a;
        prev = insert_tail;
      }
    }
    if (b != nullptr) {
      prev->next = b;
    }
    return merged_list;
  }
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    vector<ListNode *> curr(lists);

    while (curr.size() != 1) {
      vector<ListNode *> next;
      for (int i = 0; i < curr.size(); i += 2) {
        if (i + 1 < curr.size()) {
          next.push_back(mergeTwoLists(curr[i], curr[i + 1]));
        } else {
          next.push_back(curr[i]);
        }
      }
      curr = next;
    }
    return curr[0];
  }
};