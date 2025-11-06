class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        vector<int> res(n);
        for(int i = 0; i < n; i++){
            res[(i + k) % n] = nums[i];
        }
        nums = move(res);
    }
};