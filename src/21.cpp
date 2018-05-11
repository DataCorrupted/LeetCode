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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* a = l1;
        ListNode* b = l2;
        if (a == nullptr) { return b; }
        if (b == nullptr) { return a; }
        if (a->val > b->val){
            swap(a, b);
        }
        ListNode* merged_list = a;
        ListNode* prev = a;
        a = a->next;
        while (a != nullptr && b != nullptr){
            if (a->val < b->val){
                prev = a;
                a = a->next;
            } else {
                ListNode* insert = b;
                
                b = b->next;
                
                prev->next = insert;
                insert->next = a;
                prev = prev->next;
            }
        }
        if (b != nullptr){
            prev->next = b;
        }
        return merged_list;
    }        
};