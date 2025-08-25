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
    TreeNode* ans;
public:
    bool check(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return false;
        bool mid = (root == p || root == q);
        bool left = check(root->left, p, q);
        if(mid & left){
            ans = root;
            return true;
        }
        bool right = check(root->right, p, q);
        if(mid & right || left & right) {
            ans = root;
            return true;
        }
        return mid || left || right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans = NULL;
        check(root, p, q);
        return ans;
    }
};