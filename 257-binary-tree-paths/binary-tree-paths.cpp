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
private:
    vector<string> ans;
public:
    void paths(string& s, TreeNode* root){
        if(!root->left && !root->right){
            ans.push_back(s);
            return;
        }
        s.push_back('-');
        s.push_back('>');
        if(root->left){
            string temp = to_string(root->left->val);
            s += temp;
            paths(s, root->left);
            for(int i = 0; i < temp.size(); i++) s.pop_back();
        }
        if(root->right){
            string temp = to_string(root->right->val);
            s += temp;
            paths(s, root->right);
            for(int i = 0; i < temp.size(); i++) s.pop_back();
        }
        s.pop_back();
        s.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string s = to_string(root->val);
        paths(s, root);
        return ans;
    }
};