class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        
        while (curr) {
            if (!curr->left) {
                // no left subtree → visit & go right
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else {
                // find predecessor (rightmost node in left subtree)
                TreeNode* pred = curr->left;
                while (pred->right && pred->right != curr) {
                    pred = pred->right;
                }
                
                if (!pred->right) {
                    // first time we reach curr: 
                    // 1) visit it, 2) thread back, 3) go left
                    ans.push_back(curr->val);
                    pred->right = curr;
                    curr = curr->left;
                }
                else {
                    // second time: undo the thread & go right
                    pred->right = nullptr;
                    curr = curr->right;
                }
            }
        }
        
        return ans;
    }
};
