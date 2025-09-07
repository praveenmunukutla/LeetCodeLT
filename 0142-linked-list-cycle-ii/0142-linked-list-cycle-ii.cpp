/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* hare;
    ListNode* tortoise;
public:
    bool hasCycle(){
        while(hare && hare->next){
            tortoise = tortoise->next;
            hare = hare->next->next;
            if(hare == tortoise)
                return true;
        }
        return false;
    }
    
    ListNode *detectCycle(ListNode *head) {
        hare = tortoise = head;
        if(hasCycle()){
            hare = head;
            while(hare && tortoise){
                if(hare == tortoise)
                    return hare;
                hare = hare->next;
                tortoise = tortoise->next;
            }
        }
        return nullptr;
    }
};