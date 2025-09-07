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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr)
            return vector<vector<int>>{};
        
        vector<vector<int>> res;
        queue<TreeNode*> que;
        que.push(root);
        
        while(!que.empty()){
            int size = que.size();
            vector<int> tres;
            while(size--){
                TreeNode* n = que.front(); que.pop();
                tres.push_back(n->val);
                if(n->left)
                    que.push(n->left);
                if(n->right)
                    que.push(n->right);
            }
            res.push_back(tres);
        }
        
        return move(res);        
    }
};