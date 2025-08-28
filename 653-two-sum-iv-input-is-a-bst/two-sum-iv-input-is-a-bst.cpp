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
    TreeNode* next(stack<TreeNode*>& s, bool isLow){
        if(s.empty()) return nullptr;
        TreeNode* node = s.top();
        s.pop();
        TreeNode* curr = isLow ? node->right : node->left;
        while(curr){
            s.push(curr);
            curr = isLow ? curr->left : curr->right;
        }
        return node;
    }

    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> low, high;
        TreeNode *l = root, *r = root;
        while(l) low.push(l), l = l->left;
        while(r) high.push(r), r = r->right;
        l = next(low, true);
        r = next(high, false);
        while(l != r){
            if(l->val + r->val == k){
                return true;
            }else if(l->val + r->val > k){
                r = next(high, false);
            }else{
                l = next(low, true);
            }
        }
        return false;
    }
};