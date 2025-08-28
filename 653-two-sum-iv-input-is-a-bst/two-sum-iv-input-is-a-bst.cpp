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

 static const bool __boost = []() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	return std::ios_base::sync_with_stdio(false);
	}();

const size_t BUFFER_SIZE = 0x6fafffff;
alignas(std::max_align_t) char buffer[BUFFER_SIZE];
size_t buffer_pos = 0;
void* operator new(size_t size) {
	constexpr std::size_t alignment = alignof(std::max_align_t);
	size_t padding = (alignment - (buffer_pos % alignment)) % alignment;
	size_t total_size = size + padding;
	char* aligned_ptr = &buffer[buffer_pos + padding];
	buffer_pos += total_size;
	return aligned_ptr;
}
void operator delete(void* ptr, unsigned long) {}
void operator delete(void* ptr) {}
void operator delete[](void* ptr) {}

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
            long long sum = (long long)a->val + (long long)b->val;
            if (sum == k) return true;
            if (sum < k)  a = L.next();
            else          b = R.next();
        }
        return false;
    }
};
