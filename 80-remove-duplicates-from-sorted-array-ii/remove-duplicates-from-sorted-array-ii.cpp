class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0, j=1;
        int ct=1, ans=1;
        while(j<nums.size()){
            if(nums[i]==nums[j] and ct<2){
                ans++;
                i++;
                swap(nums[i],nums[j]);
                ct++;
                //j++;
            }
            else if(nums[i]!=nums[j]){
                i++;
                ans++;
                swap(nums[i], nums[j]);
                ct=1;
            }
            j++; 
        }
        return ans;
    }
};