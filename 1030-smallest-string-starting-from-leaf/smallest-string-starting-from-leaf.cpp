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
private: vector<int> v;
         string ans;
         string s = "abcdefghijklmnopqrstuvwxyz";
public:
    void func(TreeNode* root){
        v.push_back(root->val);
        if(root->left==nullptr and root->right==nullptr){
            string temp;
            int n=v.size();
            for(int i = n-1;i>=0;i--){
                temp.push_back(s[v[i]]);
            }
            if(temp.compare(ans) < 0 or ans.empty()){
                ans=temp;
            }
        }
        if(root->left)
        smallestFromLeaf(root->left);
        if(root->right)
        smallestFromLeaf(root->right);
        v.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
       func(root);
       return ans;
    }
};