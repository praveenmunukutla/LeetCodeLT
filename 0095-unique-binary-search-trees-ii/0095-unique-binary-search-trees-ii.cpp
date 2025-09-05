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
	vector<vector<vector<TreeNode*>>> cache;
public:
	void generateTreesUtil(int start, int end, vector<TreeNode*>& ret) {
		if (start > end) {
			ret.push_back(nullptr);
			return;
		}
		if (cache[start - 1][end - 1].empty() == false) {
			ret = cache[start - 1][end - 1];
			return;
		}


		//take every number and get left and right vectors.
		// add the each left node and right node to the root number i.
		// add a 2x2 cache;
		for (int i = start; i <= end; i++) {
			vector<TreeNode*> left, right;
			generateTreesUtil(start, i - 1, left);
			generateTreesUtil(i + 1, end, right);

			for (int j = 0; j < left.size(); j++) {
				for (int k = 0; k < right.size(); k++) {
					TreeNode* node = new TreeNode(i);
					node->left = left[j];
					node->right = right[k];
					ret.push_back(node);
				}
			}
		}

		cache[start - 1][end - 1] = ret;
	}

	vector<TreeNode*> generateTrees(int n) {
        if(n == 0)
            return vector<TreeNode*>{};
        
		vector<TreeNode*> ret;
		cache.resize(n, vector<vector<TreeNode*>>(n));
		generateTreesUtil(1, n, ret);
		return ret;
	}
};