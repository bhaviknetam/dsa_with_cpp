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
