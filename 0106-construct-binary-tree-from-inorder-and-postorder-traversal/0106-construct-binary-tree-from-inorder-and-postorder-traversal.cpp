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
    vector<int> minorder;
    vector<int> mpostorder;
public:
    TreeNode* buildTreeUtil(int& postindex, int start, int end){
        if(start > end)
            return nullptr;
        
        int pval = mpostorder[postindex--];
        TreeNode* root = new TreeNode(pval);
        if(left == right)
            return root;

        int index;
        for(index = start; index <= end; index++){
            if(minorder[index] == pval)
                break;
        }

        
        root->right = buildTreeUtil(postindex, index+1, end);
        root->left = buildTreeUtil(postindex, start, index-1);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        minorder = move(inorder);
        mpostorder = move(postorder);
        int pindex = mpostorder.size()-1;
        return buildTreeUtil(pindex, 0, minorder.size()-1);
    }
};