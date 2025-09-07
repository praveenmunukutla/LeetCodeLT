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
    vector<vector<int>> res;
public:
    void pathSumUtil(TreeNode* root, vector<int> vec, int sum){
        if(root == nullptr)        
            return;
        
        if(root->left == nullptr && root->right == nullptr && sum == root->val){
            vec.push_back(sum);
            res.push_back(vec);
            return;
        }
        
        vec.push_back(root->val);
        pathSumUtil(root->left, vec, sum-root->val);
        pathSumUtil(root->right, vec, sum-root->val);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root == nullptr)
            return res;

        vector<int> v;
        pathSumUtil(root, v, sum);
        return res;
    }
};