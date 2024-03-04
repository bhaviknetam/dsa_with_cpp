class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i =0, j =1, ct=0;
        while(j<nums.size()){
            if(nums[i] != nums[j]){
                i++;
                swap(nums[j], nums[i]);
                ct++;
            }
            j++;
        }
        return ct+1;
    }
};