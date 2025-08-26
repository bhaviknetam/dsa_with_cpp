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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        stack<TreeNode*> s;
        TreeNode* root = new TreeNode(postorder[n - 1]);
        s.push(root);
        int inIndex = n-1;
        for(int i = n - 2; i >= 0; i--){
            int val = postorder[i];
            auto node = s.top();
            if(node->val != inorder[inIndex]){
                node->right = new TreeNode(val);
                s.push(node->right);
            }else{
                while(!s.empty() && s.top()->val == inorder[inIndex]){
                    node = s.top();
                    s.pop();
                    inIndex--;
                }
                node->left = new TreeNode(val);
                s.push(node->left);
            }
        }
        return root;
    }
};