#ifdef DEBUG

#include "ListNodeG.hpp"
typedef ListNodeG<int> ListNode;

#endif

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		ListNode* dummyHead = new ListNode(-1);
		dummyHead->next = head;
		ListNode* prev = dummyHead;
		ListNode* curr = dummyHead;
		while (curr){
			prev = curr;
			curr = curr->next;

			while (curr && curr->val == val){
				prev->next = curr->next;
				curr->next = NULL;
				delete curr;
				curr = prev->next;
			}
		}
		head = dummyHead->next;
		dummyHead->next = NULL;
		delete dummyHead;
		return head;
	}
};

#ifdef DEBUG
#include "DebugUtil.h"

REGISTER_TEST(example0){
	int val = 6;
	ListNode* head = ListNode::vectorToListNode({1, 2, 6, 3, 4, 5, 6});
	ListNode* groundTruth = ListNode::vectorToListNode({1, 2, 3, 4, 5});
	bool result = (*Solution().removeElements(head, val)) == (*groundTruth);
	delete head;
	delete groundTruth;
	return result;
}
REGISTER_TEST(example1){
	int val = 7;
	ListNode* head = ListNode::vectorToListNode({1, 2, 6, 3, 4, 5, 6});
	ListNode* groundTruth = ListNode::vectorToListNode({1, 2, 6, 3, 4, 5, 6});
	bool result = (*Solution().removeElements(head, val)) == (*groundTruth);
	delete head;
	delete groundTruth;
	return result;
}
REGISTER_TEST(example2){
	int val = 1;
	ListNode* head = ListNode::vectorToListNode({1, 1, 1, 1});
	ListNode* groundTruth = NULL;
	bool result = (*Solution().removeElements(head, val)) == (*groundTruth);
	// In this case both groundTruth and head are null.
	return result;
}
#endif