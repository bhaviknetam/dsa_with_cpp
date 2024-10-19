class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        int idx = -1, mx = -1;
        for (int i = 0; i < n; i++) {
            if (mx < height[i]) {
                mx = height[i];
                idx = i;
            }
        }
        mx = height[0];
        for (int i = 1; i <= idx; i++) {
            if (height[i] >= mx) {
                mx = height[i];
            } else {
                ans += mx - height[i];
            }
        }
        mx = height[n - 1];
        for (int i = n - 2; i >= idx; i--) {
            if (height[i] >= mx) {
                mx = height[i];
            } else {
                ans += mx - height[i];
            }
        }
        return ans;
    }
};