class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        int i = 0, j = 0;
        long long ans = 0, sum = 0;
        while(j < n){
            sum+=nums[j];
            while(i < j && (j-i+1)*sum >= k){
                sum-=nums[i];
                i++;
            }
            if(j > i){
                ans += (j - i);
            }
            if(nums[j] < k) ans++;
            // cout << i << ' ' <<j<<' '<<ans<<';';
            j++;
        }
        return ans;
    }
};