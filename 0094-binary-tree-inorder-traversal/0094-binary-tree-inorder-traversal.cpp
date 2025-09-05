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
    vector<int> res;
public:
    void inorderUtil(TreeNode* root){
        if(root == nullptr)
            return;
        
        stack<TreeNode*> sta;
        TreeNode* curr = root;
        while(curr != nullptr || sta.empty() == false){
            while(curr){
                sta.push(curr);
                curr = curr->left;
            }
            
            TreeNode* temp= sta.top(); sta.pop();
            res.push_back(temp->val);
            
            curr = temp->right;
        }
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        inorderUtil(root);
        return move(res);
    }
};