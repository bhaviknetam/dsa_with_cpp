class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        int n= nums.size();
        int pos = n-1;
        vector<int> ans(n);
        while(left <= right){
            if(abs(nums[left]) > abs(nums[right])){
                ans[pos] = nums[left]*nums[left];
                left++;
            }else{
                ans[pos] = nums[right]*nums[right];
                right--;
            }
            pos--;
        }
        return ans;
    }
};