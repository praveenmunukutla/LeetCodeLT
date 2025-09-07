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
    ListNode* middle(ListNode* head){
        if(head == nullptr)
            return nullptr;
        
        ListNode* rab = head;
        ListNode* hare = head;
        ListNode* prev = nullptr;
        while(hare && hare->next){
            prev = rab;
            rab = rab->next;
            hare = hare->next->next;
        }
        if(prev)
            prev->next = nullptr;
        return rab;
    }
    
    ListNode* reverse(ListNode* head){
        if(head == nullptr)
            return nullptr;
        
        ListNode* prev = nullptr;
        while(head){
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        
        return prev;
    }
    
    void print(ListNode* node){
        if(node == nullptr)
            return;
        cout<<node->val<<" ";
        print(node->next);
    }
    
    void reorderList(ListNode* head) {
        if(head == nullptr)
            return;
        
        ListNode* middlem = middle(head);
        ListNode* rHead = reverse(middlem);        
        ListNode* prev = nullptr;
        while(head && rHead){
            ListNode* hnext = head->next;
            ListNode* rhnext = rHead->next;
            
            head->next = rHead;
            rHead->next = hnext;
            
            prev = rHead;
            
            head = hnext;
            rHead = rhnext;
        }
        
        if(rHead)
            prev->next = rHead;
    }
};