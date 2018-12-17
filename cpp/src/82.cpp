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
		ListNode* dummyHead = new ListNode(-1);
		dummyHead->next = head;

		ListNode* prev = dummyHead;
		ListNode* curr = head;

		while (curr){
			if (curr->next && curr->val == curr->next->val){
				int toDeleteVal = curr->val;
				while (prev->next && prev->next->val == toDeleteVal){
					deleteNext(prev);
				}
				// Curr will be invalid after deletion, only prev is.
				curr = prev->next;
			} else {
				prev = curr;
				curr = curr->next;
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
REGISTER_TEST(example_1){
	ListNode* head = ListNode::vectorToListNode({1, 1, 2});
	ListNode* groundTruth = ListNode::vectorToListNode({2});
	head = Solution().deleteDuplicates(head);
	bool result = (*head == *groundTruth);
	delete head;
	return result;
}
REGISTER_TEST(example_2){
	ListNode* head = ListNode::vectorToListNode({1, 1, 2, 3, 3});
	ListNode* groundTruth = ListNode::vectorToListNode({2});
	head = Solution().deleteDuplicates(head);
	bool result = (*head == *groundTruth);
	delete head;
	return result;	
}
REGISTER_TEST(example_3){
	ListNode* head = ListNode::vectorToListNode({1, 2, 3, 3, 4, 4, 5});
	ListNode* groundTruth = ListNode::vectorToListNode({1, 2, 5});
	head = Solution().deleteDuplicates(head);
	bool result = (*head == *groundTruth);
	delete head;
	return result;	
}
REGISTER_TEST(example_4){
	ListNode* head = ListNode::vectorToListNode({1, 1, 1, 2, 3});
	ListNode* groundTruth = ListNode::vectorToListNode({2, 3});
	head = Solution().deleteDuplicates(head);
	bool result = (*head == *groundTruth);
	delete head;
	return result;	
}
REGISTER_TEST(empty){
	ListNode* head = ListNode::vectorToListNode({});
	ListNode* groundTruth = ListNode::vectorToListNode({});
	head = Solution().deleteDuplicates(head);
	bool result = (*head == *groundTruth);
	delete head;
	return result;	
}
#endif