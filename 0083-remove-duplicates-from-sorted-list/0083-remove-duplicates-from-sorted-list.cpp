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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr)
            return nullptr;

        ListNode* thead = head;
        ListNode* fhead = thead;
        ListNode* prev = fhead;
        while(fhead){
            if(fhead->val != prev->val){
                prev->next = fhead;
                prev = fhead;
            }
            fhead = fhead->next;
        }
        prev->next = nullptr;
        return thead;
    }
};