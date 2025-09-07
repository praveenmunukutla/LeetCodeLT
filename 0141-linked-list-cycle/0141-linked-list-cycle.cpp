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
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)
        return false;

    ListNode *sp=head, *fp=head;
    cout<<sp->val<<" "<<fp->val<<endl;
    while(fp != NULL && fp->next != NULL)
    {
        cout<<sp->val<<" "<<fp->val<<endl;
        sp=sp->next;
        fp = fp->next->next;
        if(sp == fp)
        {
            return true;
        }
    }
    return false;
    }
};