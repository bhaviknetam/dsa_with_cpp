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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<long long,TreeNode*>> q;
        q.push({0, root});
        long long ans = 0;
        while(!q.empty()){
            int sz = q.size();
            long long start = q.front().first, last;
            for(int i = 0; i < sz; i++){
                auto [idx, node] = q.front();
                q.pop();
                idx -= start;
                last = idx;
                if(node->left) q.push({2 * idx, node->left});
                if(node->right) q.push({2 * idx + 1, node->right});
            }
            ans = max(ans, last + 1);
        }
        return ans;
    }
};