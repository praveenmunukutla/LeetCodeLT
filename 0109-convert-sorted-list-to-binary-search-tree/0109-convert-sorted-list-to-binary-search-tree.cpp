class Solution {
public:
	int len(ListNode* head){
		int count = 0;
		while (head){
			count++;
			head = head->next;
		}
		return count;
	}

	TreeNode* sortedListToBSTUtil(ListNode** head, int len){
		if (len <= 0)
			return nullptr;

		TreeNode* left = sortedListToBSTUtil(head, len / 2);
		TreeNode* root = new TreeNode((*head)->val);
		(*head) = (*head)->next;
		root->left = left;
		root->right = sortedListToBSTUtil(head, len - len / 2 - 1);
		return root;
	}

	TreeNode* sortedListToBST(ListNode* head) {
		if (head == nullptr)
			return nullptr;

		int length = len(head);
		return sortedListToBSTUtil(&head, length);
	}
};