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
    
    void recurque(queue<TreeNode*> q){
        if(q.empty() == true)
            return;

        queue<TreeNode*> nq;
        vector<int> tr;
        while(!q.empty()){
            TreeNode* t = q.front(); q.pop();
            tr.push_back(t->val);
            if(t->left){
                nq.push(t->left);
            }
            if(t->right){
                nq.push(t->right);
            }
        }
        recurque(nq);
        res.push_back(tr);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == nullptr)
            return vector<vector<int>>{};
        
        queue<TreeNode*> que;    
        que.push(root);
        recurque(que);
        return res;
    }
};