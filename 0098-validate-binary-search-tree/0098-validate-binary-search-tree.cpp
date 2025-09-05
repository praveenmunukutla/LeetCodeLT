/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef long long int lli;

class Solution {
public:
    bool isValidBSTUtil(TreeNode* root, lli min, lli max){
        if(root == nullptr)
            return true;
        
        if(root->val <= min || root->val >= max)
            return false;
        
        return isValidBSTUtil(root->left, min, root->val) && isValidBSTUtil(root->right, root->val, max);
    }

    bool isValidBST(TreeNode* root) {
        return isValidBSTUtil(root, LLONG_MIN, LLONG_MAX);
    }
};