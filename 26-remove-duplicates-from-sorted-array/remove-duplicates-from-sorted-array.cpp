class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0;
        int n = nums.size();
        while(i < nums.size()){
            nums[j] = nums[i];
            while(i < n && nums[i] == nums[j]) i++;
            j++;
        }
        return j;
    }
};