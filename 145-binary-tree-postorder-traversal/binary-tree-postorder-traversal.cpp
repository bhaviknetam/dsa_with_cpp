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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        while(curr){
            if(!curr->right){
                ans.push_back(curr->val);
                curr = curr->left;
            }else{
                TreeNode* last = curr->right;
                while(last->left && last->left != curr){
                    last = last->left;
                }
                if(!last->left){
                    ans.push_back(curr->val);
                    last->left = curr;
                    curr = curr->right;
                }else{
                    last->left = NULL;
                    curr = curr->left;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};