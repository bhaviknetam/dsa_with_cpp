/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {};
        map<int, multiset<pair<int, int>>> m;
        queue<pair<pair<int, int>, TreeNode*>> q;
        q.push({{0, 0}, root});
        while(!q.empty()){
            auto [loc, node] = q.front();
            int row = loc.first;
            int col = loc.second;
            q.pop();
            m[col].insert({row, node->val});
            if(node->left) q.push({{row+1, col-1}, node->left});
            if(node->right) q.push({{row+1, col+1}, node->right});
        }
        vector<vector<int>> ans;
        for(auto& s : m){
            vector<int> v;
            for(auto& [row, val] : s.second){
                v.push_back(val);
            }
            ans.push_back(v);
        }
        return ans;
    }
};