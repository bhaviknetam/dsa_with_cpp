class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int jumps = 1;
        int maxi = nums[0], temp=0;
        int j=0;
        while(j <= maxi){
            if(j + nums[j] > temp){
                temp = j+nums[j];
            }
            if(j == maxi){
                maxi = temp;
                jumps++;
            }
            if(maxi >= nums.size()-1){
                break;
            }
            j++;
        }
        return jumps;
    }
};