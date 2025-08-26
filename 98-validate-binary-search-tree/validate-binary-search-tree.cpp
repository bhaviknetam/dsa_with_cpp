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
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        TreeNode* curr = root;
        long long prev = LLONG_MIN;
        bool valid = true;
        while(curr){
            if(!curr->left){
                if(curr->val <= prev) valid = false;
                prev = curr->val;
                curr = curr->right;
            }else{
                TreeNode* last = curr->left;
                while(last->right && last->right != curr){
                    last = last->right;
                }
                if(!last->right){
                    last->right = curr;
                    curr = curr->left;
                }else{
                    last->right = nullptr;
                    if(curr->val <= prev) valid = false;
                    prev = curr->val;
                    curr = curr->right;
                }
            }
        }
        return valid;
    }
};