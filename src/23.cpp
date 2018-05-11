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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b){
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
                ListNode* insert_head = b;
                ListNode* insert_tail = b;
                
                while (insert_tail->next != nullptr && insert_tail->next->val < a->val){
                    insert_tail = insert_tail->next;
                }
                
                b = insert_tail->next;
                
                prev->next = insert_head;
                insert_tail->next = a;
                prev = insert_tail;
            }
        }
        if (b != nullptr){
            prev->next = b;
        }
        return merged_list;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> curr(lists);
        
        while (curr.size() != 1){
            vector<ListNode*>next;
            for (int i=0; i<curr.size(); i += 2){
                if (i + 1 < curr.size()){
                    next.push_back(mergeTwoLists(curr[i], curr[i+1]));
                } else {
                    next.push_back(curr[i]);
                }
            }
            curr = next;
        }
        return curr[0];
    }
};