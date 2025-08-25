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
private:
    unordered_map<int, int> preMap, inMap;

public:
    TreeNode* createTree(int preL, int preR, int inL, int inR, vector<int>& pre, vector<int>& in) {
        if (inR < inL)
            return nullptr;
        int curr = pre[preL];
        TreeNode* root = new TreeNode(curr);
        if (inR == inL)
            return root;
        int tot = inMap[curr] - inL;
        root->left =
            createTree(preL + 1, preL + tot, inL, inMap[curr] - 1, pre, in);
        root->right =
            createTree(preL + tot + 1, preR, inMap[curr] + 1, inR, pre, in);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for (int i = 0; i < n; i++) {
            preMap[preorder[i]] = i;
            inMap[inorder[i]] = i;
        }
        return createTree(0, n - 1, 0, n - 1, preorder, inorder);
    }
};