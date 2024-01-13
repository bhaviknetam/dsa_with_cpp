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
   unordered_map<int, vector<int>> g;

    void conversion(TreeNode* root) {
        if (root == nullptr) return;
        
        if (root->left != nullptr) {
            g[root->val].push_back(root->left->val);
            g[root->left->val].push_back(root->val);
            conversion(root->left);
        }
        
        if (root->right != nullptr) {
            g[root->val].push_back(root->right->val);
            g[root->right->val].push_back(root->val);
            conversion(root->right);
        }
    }

    int injecttime(int start, unordered_map<int, bool>& vis) {
        int time = 0;
        if (vis[start]) return 0;

        vis[start] = true;

        for (int neighbor : g[start]) {
            if(!vis[neighbor])
            time = max(time, 1 + injecttime(neighbor, vis));
        }

        return time;
    }

    int amountOfTime(TreeNode* root, int start) {
        if (root == nullptr) return 0;

        conversion(root);

        unordered_map<int, bool> vis;
        return injecttime(start, vis);
    }
};