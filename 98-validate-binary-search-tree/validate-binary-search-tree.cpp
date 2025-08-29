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
    pair<long,long> dfs(TreeNode* root, bool &ok) {
        if (!root) {
            return {LLONG_MAX, LLONG_MIN};
        }

        auto left = dfs(root->left, ok);
        auto right = dfs(root->right, ok);

        // If already invalid, bubble it up
        if (!ok) return {0,0};

        if (root->val <= left.second || root->val >= right.first) {
            ok = false;
            return {0,0};
        }

        // Return updated min and max for this subtree
        return {min((long)root->val, left.first),
                max((long)root->val, right.second)};
    }

    bool isValidBST(TreeNode* root) {
        bool ok = true;
        dfs(root, ok);
        return ok;
    }
};
