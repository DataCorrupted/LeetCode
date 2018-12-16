#ifdef DEBUG

#include "ListNodeG.hpp"
typedef ListNodeG<int> ListNode;

#endif

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head) { return NULL; }
		// Measure the length and find the last node.
		int length = 0;
		ListNode* curr = head;
		ListNode* prev = NULL;
		while (curr){
			length++;
			prev = curr;
			curr = curr->next;
		}

		// Loopize the list.
		prev->next = head;

		// Restart the iteration
		curr = prev;
		for (int i = 0; i<length - (k % length); i++){
			curr = curr->next;
		}

		// Redefine the head and cut the link before it.
		head = curr->next;
		curr->next = NULL;
		return head;
	}
};

#ifdef DEBUG
#include "DebugUtil.h"

REGISTER_TEST(example_1){
	ListNode* head = ListNode::vectorToListNode({1, 2, 3, 4, 5});
	int k = 2;
	ListNode* groundTruth = ListNode::vectorToListNode({4, 5, 1, 2, 3});
	head = Solution().rotateRight(head, k);
	bool result = ListNode::listsEq(head, groundTruth);
	delete head;
	delete groundTruth; 
	return result;
}
REGISTER_TEST(example_2){
	ListNode* head = ListNode::vectorToListNode({0, 1, 2});
	int k = 4;
	ListNode* groundTruth = ListNode::vectorToListNode({2, 0, 1});
	head = Solution().rotateRight(head, k);
	bool result = ListNode::listsEq(head, groundTruth);
	delete head;
	delete groundTruth;
	return result;	
}
REGISTER_TEST(example_3){
	ListNode* head = ListNode::vectorToListNode({1, 2});
	int k = 0;
	ListNode* groundTruth = ListNode::vectorToListNode({1, 2});
	head = Solution().rotateRight(head, k);
	bool result = ListNode::listsEq(head, groundTruth);
	delete head;
	delete groundTruth;
	return result;	
}
REGISTER_TEST(empty){
	ListNode* head = NULL;
	int k = 4;
	ListNode* groundTruth = NULL;
	head = Solution().rotateRight(head, k);
	bool result = ListNode::listsEq(head, groundTruth);
	return result;	
}
#endif