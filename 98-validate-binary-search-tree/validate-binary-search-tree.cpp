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
        struct Frame {
            TreeNode* node;
            int state;
            pair<long, long> leftVal, rightVal;
        };
        stack<Frame> s;
        s.push({root, 0, {0, 0}, {0, 0}});
        pair<long, long> result = {0, 0}; // min, max
        while(!s.empty()){
            auto &f = s.top();
            auto u = f.node;
            if(!u){
                result = {LLONG_MAX, LLONG_MIN};
                s.pop();
                continue;
            }
            if(f.state == 0){
                f.state = 1;
                s.push({u->left, 0, {0,0}, {0,0}});
            }else if(f.state == 1){
                f.leftVal = result;
                f.state = 2;
                s.push({u->right, 0, {0,0}, {0,0}});
            }else{
                f.rightVal = result;
                if(u->val>f.leftVal.second && u->val<f.rightVal.first){
                    result = {min((long)u->val, f.leftVal.first),
                    max((long)u->val, f.rightVal.second)};
                    s.pop();
                }else return false;
            }
        }
        return true;
    }
};