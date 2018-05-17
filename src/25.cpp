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
    void reverse(ListNode* head, ListNode* end){
        ListNode* curr = head;
        ListNode* prev = end->next;
        ListNode* next = head->next;
        while (true){
            curr->next = prev;
            prev = curr;
            curr = next;
            if (curr = end->next) { return; }
            next = next->next;
        }
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
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
            reverse(head->next, end);
            ListNode* next_head = head->next;
            head->next = end;
            head = next_head;
            end = next_head;
            
        }
    }
};