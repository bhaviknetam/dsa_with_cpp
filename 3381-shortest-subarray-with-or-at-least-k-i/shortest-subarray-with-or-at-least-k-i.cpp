class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int target) {
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int val=0;
                for(int k=i;k<=j;k++){
                    val|=nums[k];
                }
                if(val>=target){
                    ans=min(ans,j-i+1);
                }
            }
        }
        return (ans!=INT_MAX)?ans:-1;
    }
};