class Solution {
public:
    void inorder(TreeNode* root, vector<int>& vt) {
        if (!root) return;
        inorder(root->left, vt) , vt.push_back(root->val) , inorder(root->right, vt);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        inorder(root, nums);
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int sum = nums[l] + nums[r];
            if (sum == k) return true;
            else if (sum < k) l++;
            else r--;
        }
        return false;
    }
};
