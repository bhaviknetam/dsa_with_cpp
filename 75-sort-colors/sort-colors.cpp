
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = n - 1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                swap(nums[i], nums[s]);
                s++;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i]==2){
                swap(nums[i], nums[e]);
                e--;
            }
        }
    }
};