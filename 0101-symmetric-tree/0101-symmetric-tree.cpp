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
public:
    bool ismirror(TreeNode* root1, TreeNode* root2){
        if(root1 == nullptr && root2 == nullptr)
            return true;
        if(root1 == nullptr || root2 == nullptr)
            return false;
        return (root1->val == root2->val) && 
               ismirror(root1->left, root2->right) && 
               ismirror(root1->right, root2->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        return ismirror(root, root); 
    }
};