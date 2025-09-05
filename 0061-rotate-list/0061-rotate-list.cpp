/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* thead;
    ListNode* lnode;
    ListNode* lknode;
    ListNode* anode;
public:
    int length(){
        int count = 0;
        ListNode* htemp = thead;
        while(htemp){
            count++;
            if(htemp->next == nullptr)
                lnode = htemp;
            htemp = htemp->next;
        }
        return count;
    }
    
    void process(int k){
        ListNode* ftemp = thead;
        ListNode* fnode = thead;
        ListNode* prev = nullptr;
        while(k--){
            ftemp = ftemp->next;
        }
        while(ftemp){
            prev = fnode;
            fnode = fnode->next;
            ftemp = ftemp->next;
        }
        
        anode = prev->next;
        prev->next = nullptr;
        lnode->next = thead;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || head == nullptr)
            return head;
        thead = head;
        int len = length();
        k = k % len;
        if(k == 0)
            return head;
        process(k);
        return anode;
    }
};