/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int sum = 0;
public:
    void sumNumbersUtil(TreeNode* root, int num) {
        if(root == nullptr)
            return;
        
        if(root->left == nullptr && root->right == nullptr){
            sum += num*10+root->val;
            return;
        }

        num = num*10 + root->val;
        sumNumbersUtil(root->left, num);
        sumNumbersUtil(root->right, num);
    }

    int sumNumbers(TreeNode* root) {
        sum = 0;
        sumNumbersUtil(root, 0);
        return sum;
    }
};