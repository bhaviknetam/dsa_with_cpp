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

struct BSTIter {
    std::stack<TreeNode*> st;
    bool forward; // true => next smallest (inorder), false => next largest (reverse inorder)

    BSTIter(TreeNode* root, bool forward) : forward(forward) {
        pushPath(root);
    }

    void pushPath(TreeNode* node) {
        while (node) {
            st.push(node);
            node = forward ? node->left : node->right;
        }
    }

    // Returns next node in chosen order, or nullptr when exhausted
    TreeNode* next() {
        if (st.empty()) return nullptr;
        TreeNode* node = st.top(); st.pop();
        if (forward) pushPath(node->right);
        else         pushPath(node->left);
        return node;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        BSTIter L(root, /*forward=*/true);   // smallest upwards
        BSTIter R(root, /*forward=*/false);  // largest downwards

        TreeNode* a = L.next();
        TreeNode* b = R.next();

        while (a && b && a != b) {
            long long sum = (long long)a->val + (long long)b->val; // avoid overflow
            if (sum == k) return true;
            if (sum < k)  a = L.next();
            else          b = R.next();
        }
        return false;
    }
};
