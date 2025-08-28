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
private: int counter = 0;
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return -1;
        int l = kthSmallest(root->left, k);
        if(l != -1) return l;
        counter++;
        if(counter == k){
            return root->val;
        }
        return kthSmallest(root->right, k);
    }
};