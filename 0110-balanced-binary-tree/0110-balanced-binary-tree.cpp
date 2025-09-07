/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define ABS(a,b) ((a)>(b)?(a-b):(b-a))
#define MAX(a,b) ((a)>(b)?(a):(b))

class Solution {
    struct ret{
        int height;
        int balanced;
        ret(){
            height = 0;
            balanced = true;
        }
    };
public:
    ret height(TreeNode* root){
        if(root == nullptr)
            return ret();
        
        ret lh = height(root->left);
        ret rh = height(root->right);
        ret cur;
        
        cur.balanced = lh.balanced & rh.balanced;
        int diff = ABS(lh.height,rh.height);
        if(diff > 1)
            cur.balanced = false;
        cur.height = MAX(lh.height, rh.height)+1;
        return cur;
    }
    
    bool isBalanced(TreeNode* root) {
        ret r = height(root);
        return r.balanced;
    }
};