class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int i =0, j = n-1, ct =0;
        while(i <= j){
            if(nums[j] == val){
                nums[j] = 0;
                ct++;
                j--;
            } else if(nums[i] == val){
                nums[i] = 0;
                ct++;
                swap(nums[i], nums[j]);
                i++;
                j--;
            } else{
                i++;
            }
        }
        return n - ct;
    }
};