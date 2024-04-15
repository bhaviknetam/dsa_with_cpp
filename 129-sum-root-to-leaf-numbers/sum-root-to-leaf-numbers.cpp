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
private: vector<int> store;
public:
    int sumNumbers(TreeNode* root) {
        if(root==nullptr) return 0;
        store.push_back(root->val);
        int sum=0;
        if(root->left==nullptr && root->right==nullptr){
            int temp=0;
            for(int& i : store){
                temp=(temp*10+i);
            }
            sum+=temp;
        }
        sum+=sumNumbers(root->left) + sumNumbers(root->right);
        store.pop_back();
        return sum;
    }
};