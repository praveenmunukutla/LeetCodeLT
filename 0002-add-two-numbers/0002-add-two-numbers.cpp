/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* head = nullptr;
    ListNode* prev = nullptr;
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        addTwo(l1, l2, 0);
        return head;
    }

    void addTwo(ListNode*l1, ListNode*l2, int carry){
        if(l1 == nullptr && l2 == nullptr && carry == 0) return;
        int v1 = l1 ? l1->val : 0;
        int v2 = l2 ? l2->val : 0;

        int sum = v1 + v2 + carry;
        
        if(sum >= 10) carry = 1;
        else carry = 0;

        int value = sum%10;

        if(head == nullptr){
            head = new ListNode(value);
            prev = head;
        }else{
            prev->next = new ListNode(value);
            prev = prev->next;
        }

        
        addTwo(l1?l1->next:nullptr, l2?l2->next:nullptr, carry);
    }


};