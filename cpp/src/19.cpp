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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == nullptr || head == nullptr) {
            return nullptr;
        }
        ListNode* pesudo_head = new ListNode(0);
        pesudo_head->next = head;
        
        ListNode* tail = pesudo_head;
        ListNode* prev_to_delete = pesudo_head;
        for (int i=0; i<n; i++){
            tail = tail->next;
        }
        while (tail->next != nullptr){
            tail = tail->next;
            prev_to_delete = prev_to_delete->next;
        }
        prev_to_delete -> next = prev_to_delete->next->next;
        head = pesudo_head->next;
        delete pesudo_head;
        return head;   
    }
};