/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    unordered_map<int, int> inMap;

public:
    TreeNode* createTree(int preL, int preR, int inL, int inR, vector<int>& pre, vector<int>& in) {
        if (inR < inL)
            return nullptr;
        int curr = pre[preL];
        TreeNode* root = new TreeNode(curr);
        if (inR == inL)
            return root;
        int mid = inMap[curr];
        int leftSize = mid - inL;
        root->left =
            createTree(preL + 1, preL + leftSize, inL, mid-1, pre, in);
        root->right =
            createTree(preL + leftSize+ 1, preR,mid + 1, inR, pre, in);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int inIndex = 0;
        stack<TreeNode*> s;
        TreeNode* root = new TreeNode(preorder[0]);
        s.push(root);
        for(int i = 1; i < n; i++){
            int val = preorder[i];
            auto node = s.top();
            if(node->val != inorder[inIndex]){
                node->left = new TreeNode(val);
                s.push(node->left);
            }else{
                while(!s.empty() && s.top()->val == inorder[inIndex]){
                    node = s.top();
                    s.pop();
                    inIndex++;
                }
                node->right = new TreeNode(val);
                s.push(node->right);
            }
        }
        return root;
    }
};