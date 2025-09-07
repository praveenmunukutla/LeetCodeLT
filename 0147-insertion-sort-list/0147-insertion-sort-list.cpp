/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* first = nullptr;
    ListNode* last = nullptr;
public:
    void insert(ListNode* node){
        if(first == nullptr && last == nullptr){
            first = last = node;
            return;
        }
        
        if(first == last){
            if(node->val > first->val){
                first->next = node;
                last = node;
            }else{
                node->next = first;
                first = node;
            }
            return;
        }
        
        ListNode* prev = nullptr;
        ListNode* ftemp = first;
        while(ftemp){
            if(node->val < ftemp->val)
                break;
            prev = ftemp;
            ftemp = ftemp->next;
        }
        
        if(prev == nullptr && ftemp == first){
            node->next = first;
            first = node;
            return;
        }
        
        node->next = prev->next;
        prev->next = node;
    }
    
    ListNode* insertionSortList(ListNode* head) {
        ListNode* next;
        while(head){
            next = head->next;
            head->next = nullptr;
            insert(head);
            head = next;
        }
        return first;
    }
};