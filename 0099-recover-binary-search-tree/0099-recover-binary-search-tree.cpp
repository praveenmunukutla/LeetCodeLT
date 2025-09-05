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
    TreeNode* first = nullptr;
    TreeNode* middle = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = new TreeNode(INT_MIN);
public:
    void recoverTreeUtil(TreeNode* root){
        if(root == nullptr)
            return;
        
        recoverTreeUtil(root->left);
        cout<<root->val<<" "<<prev->val<<" ";
        if(first == nullptr && prev->val > root->val){
            first = prev;
            middle = root;
            cout<<"first set"<<endl;
        }
        else if(first != nullptr && prev->val > root->val){
            second = root;
            cout<<"second set"<<endl;
        }
        prev = root;
        recoverTreeUtil(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        if(root == nullptr)
            return;
        
        recoverTreeUtil(root);
        if(first && second)
            swap(first->val, second->val);
        else if(first && middle)
            swap(first->val, middle->val);
    }
};