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
    void preorder(TreeNode* root, vector<int>& m){
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr){
            m.push_back(root->val);
        }
        preorder(root->left,m);
        preorder(root->right,m);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> m1, m2;
        preorder(root1, m1);
        preorder(root2, m2);
        if(m1.size()!=m2.size()) return false;
        for (auto it1 = m1.begin(), it2 = m2.begin(); it1 != m1.end(), it2 != m2.end(); ++it1, ++it2) {
    if (*it1 != *it2) {
        return false;
    }
}
        return true;
    }
};