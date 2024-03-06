class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0, val=0;
        for(auto num : nums){
            if(count==0){
                val=num;
            }
            if(num==val){
                count++;
            }else{
                count--;
            }
        }
        return val;
    }
};