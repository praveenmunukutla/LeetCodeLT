/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
	void connectUtil(Node* root){
		queue<Node*> que;
		que.push(root);
		while (!que.empty()){
			stack<Node*> sta;
			int size = que.size();
			while (size--){
				Node* temp = que.front(); que.pop();
				sta.push(temp);
				if (temp->left)
					que.push(temp->left);
				if (temp->right)
					que.push(temp->right);
			}

			Node* next = nullptr;
			while (!sta.empty()){
				Node* curr = sta.top(); sta.pop();
				curr->next = next;
				next = curr;
			}
		}
	}

	Node* connect(Node* root) {
        if(root == nullptr)
            return nullptr;
            
		connectUtil(root);
		return root;
	}
};