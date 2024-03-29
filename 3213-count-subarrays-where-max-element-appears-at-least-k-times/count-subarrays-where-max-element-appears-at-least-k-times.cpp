class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        int maxnum = *max_element(nums.begin(),nums.end());
        int n=nums.size();
        int i=0,j=0,count=0;
        while(j<n){
            if(nums[j]==maxnum){
                count++;
            }
            if(count==k){
                while(count == k){
                    ans+=(n-j);
                    if(nums[i]==maxnum) count--;
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};