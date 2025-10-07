class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 1e6;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 1; i++){
            int l = i + 1, r = n - 1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(abs(sum - target) < abs(ans - target)){
                    ans = sum;
                }
                if(sum > target){
                    r--;
                }else{
                    l++;
                }
            }
        }
        return ans;
    }
};