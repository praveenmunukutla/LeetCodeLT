/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
    unordered_map<Node*, Node*> map;
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        
        map[node] = new Node(node->val, {});
        queue<Node*> que;
        que.push(node);
        
        while(!que.empty()){
            Node* curr = que.front(); que.pop();
            for(auto n : curr->neighbors){
                if(map.find(n) == map.end()){
                    map[n] = new Node(n->val, {});
                    que.push(n);
                }
                map[curr]->neighbors.push_back(map[n]);
            }
        }
        
        return map[node];
    }
};