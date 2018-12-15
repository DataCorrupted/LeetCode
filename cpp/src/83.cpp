#ifdef DEBUG

#include "ListNodeG.hpp"
typedef ListNodeG<int> ListNode;

#endif 

class Solution {
public:
	void deleteNext(ListNode* curr){
		ListNode* next = curr->next;
		curr->next = next->next;
		next->next = NULL;
		delete next;
	}
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* curr = head;
		while (curr != NULL){
			if (curr->next && curr->next->val == curr->val){
				deleteNext(curr);
			} else {
				curr = curr->next;
			}
		}
		return head;
	}
};

#ifdef DEBUG

#include "DebugUtil.h"
REGISTER_TEST(example_1){
	ListNode* head = ListNode::vectorToListNode({1, 1, 2});
	ListNode* groundTruth = ListNode::vectorToListNode({1, 2});

	bool result = ListNode::listsEq(Solution().deleteDuplicates(head), groundTruth);
	delete head;
	return result;
}
REGISTER_TEST(example_2){
	ListNode* head = ListNode::vectorToListNode({1, 1, 2, 3, 3});
	ListNode* groundTruth = ListNode::vectorToListNode({1, 2, 3});

	bool result = ListNode::listsEq(Solution().deleteDuplicates(head), groundTruth);
	delete head;
	return result;	
}
#endif