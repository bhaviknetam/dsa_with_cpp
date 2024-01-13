/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    pair<int, int> max_min_values(TreeNode* node) {
        if (node == nullptr) return {INT_MIN, INT_MAX};
        
        pair<int, int> left_values = max_min_values(node->left);
        pair<int, int> right_values = max_min_values(node->right);
        
        int maxi = max({node->val, left_values.first, right_values.first});
        int mini = min({node->val, left_values.second, right_values.second});
        
        return {maxi, mini};
    }

    int maxAncestorDiff(TreeNode* root) {
        if (root == nullptr) return 0;

        pair<int, int> values = max_min_values(root);

        int max_diff_left = maxAncestorDiff(root->left);
        int max_diff_right = maxAncestorDiff(root->right);

        int max_diff = max({abs(root->val - values.second), abs(root->val - values.first), max_diff_left, max_diff_right});

        return max_diff;
    }

};