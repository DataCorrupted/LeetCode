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
    void reverse(ListNode* head, ListNode* end, int k){
        ListNode* curr = head;
        ListNode* prev = end->next;
        ListNode* next = head->next;

        for (int i=0; i<k; i++){
            curr->next = prev;
            prev = curr;
            curr = next;
            if (next != nullptr) { next = next->next; }
        }
       
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) { return head; }
        ListNode tmp = ListNode(0);
        ListNode* pesudo_head = &tmp;
        pesudo_head->next = head;
        ListNode* begin = pesudo_head;
        ListNode* end = pesudo_head;        
        while (true){
            for (int i=0; i<k; i++){
                end = end->next;
                if (end == nullptr){
                    return pesudo_head->next;
                }
            }
            reverse(begin->next, end, k);
            ListNode* next_head = begin->next;
            begin->next = end;
            begin = next_head;
            end = next_head;
            //cout << pesudo_head->next->next->val;
        }
        return pesudo_head->next;
    }
    ListNode* swapPairs(ListNode* head) {
        return reverseKGroup(head, 2);    
    }
};