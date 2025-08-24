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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        while(curr != NULL){
            if(!curr->left){
                ans.push_back(curr->val);
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
                    last->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};