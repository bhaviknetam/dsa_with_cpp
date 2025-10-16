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
private:
    unordered_map<int, vector<int>> adj;
    vector<int> ans;
public:
    void build_graph(TreeNode* node){
        if(node->left){
            adj[node->val].push_back(node->left->val);
            adj[node->left->val].push_back(node->val);
            build_graph(node->left);
        }
        if(node->right){
            adj[node->val].push_back(node->right->val);
            adj[node->right->val].push_back(node->val);
            build_graph(node->right);
        }
    }

    void dfs(int u, int par, int dist, int k){
        if(dist == k){
            ans.push_back(u);
            return;
        }
        for(int& v : adj[u]){
            if(v != par){
                dfs(v, u, dist + 1, k);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        build_graph(root);
        dfs(target->val, -1, 0, k);
        return ans;
    }
};