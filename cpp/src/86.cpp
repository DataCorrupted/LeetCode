#ifdef DEBUG
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
	#include <ListNodeG.hpp>
	typedef ListNodeG<int> ListNode;
#endif 

class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode* smallHead = new ListNode(0);
		ListNode* largeHead = new ListNode(0);
		ListNode* smallTail = smallHead;
		ListNode* largeTail = largeHead;

		while (head){
			if (head->val < x){
				smallTail->next = head;
				smallTail = head;
			} else {
				largeTail->next = head;
				largeTail = head;
			}
			head = head->next;
		}
		// Large Head is dummy head.
		smallTail->next = largeHead->next;
		largeTail->next = nullptr;
		ListNode* partitionedHead = smallHead->next;

		smallHead->next = nullptr; largeHead->next = nullptr;
		delete smallHead; delete largeHead;
		return partitionedHead;
	}
};

#ifdef DEBUG
REGISTER_TEST(example1){
	ListNode* head = ListNode::vectorToListNode({1, 4, 3, 2, 5, 2});
	int x = 3;
	ListNode* groundTruth = ListNode::vectorToListNode({1, 2, 2, 4, 3, 5});
	ListNode* partitionedHead = Solution().partition(head, x);
	bool result = ListNode::listsEq(partitionedHead, groundTruth);
	delete partitionedHead; delete groundTruth;
	return result;
}
#endif