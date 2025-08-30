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
private:
    unordered_map<int, Node*> m;
public:
    Node* dfs(Node* node){
        if(m[node->val]) 
            return m[node->val];
        Node* newNode = new Node(node->val);
        m[node->val] = newNode;
        for(auto neighbor : node->neighbors){
            Node* n = dfs(neighbor);
            newNode->neighbors.push_back(n);
        }
        return newNode;
    }

    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        return dfs(node);
    }
};