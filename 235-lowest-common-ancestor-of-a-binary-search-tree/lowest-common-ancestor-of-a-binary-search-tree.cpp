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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        if(p->val > q->val) return lowestCommonAncestor(root, q, p);
        TreeNode *curr = root;
        while(curr){
            if(curr == p || curr == q){
                return curr;
            }
            if(curr->val > p->val && curr->val < q->val){
                return curr;
            }
            if(q->val < curr->val) curr = curr->left;
            else curr = curr->right;
        }
        return NULL;
    }
};