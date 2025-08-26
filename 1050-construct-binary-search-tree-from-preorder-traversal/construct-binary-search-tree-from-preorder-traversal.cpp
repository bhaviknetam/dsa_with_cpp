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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() == 0) return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> s;
        s.push(root);
        for(int i = 1; i < preorder.size(); i++){
            auto node = s.top();
            int val = preorder[i];
            if(val < node->val){
                node->left = new TreeNode(val);
                s.push(node->left);
            }else{
                while(!s.empty() && s.top()->val < val){
                    node = s.top();
                    s.pop();
                }
                node->right = new TreeNode(val);
                s.push(node->right);
            }
        }
        return root;
    }
};