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
public:
    void dfs(Node* cloneNode, Node* node, unordered_map<Node*, Node*>& mpp){
        for(auto it : node->neighbors){
            if(mpp.find(it) != mpp.end()){
                cloneNode->neighbors.push_back(mpp[it]);
                continue;
            }
            Node* newNode = new Node(it->val);
            mpp[it] = newNode;
            cloneNode->neighbors.push_back(newNode);
            dfs(newNode, it, mpp);
        }
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL){
            return node;
        }
        Node* cloneNode = new Node(node->val);
        unordered_map<Node*, Node*> mpp;
        mpp[node] = cloneNode;
        dfs(cloneNode, node, mpp);
        return cloneNode;
    }
};