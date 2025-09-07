class Solution {
	vector<int> arr;
public:
	TreeNode* convert(int start, int end){
		if (start > end)
			return nullptr;
		int mid = (start + end) / 2;
		TreeNode* root = new TreeNode(arr[mid]);
		root->left = convert(start, mid - 1);
		root->right = convert(mid + 1, end);
		return root;
	}

	TreeNode* sortedArrayToBST(vector<int>& nums) {
		arr = move(nums);
		TreeNode* root = convert(0, arr.size() - 1);
		return root;
	}
};