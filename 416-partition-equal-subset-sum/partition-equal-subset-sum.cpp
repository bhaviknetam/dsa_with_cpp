class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i: nums){
            sum+=i;
        }
        if(sum & 1) return false;
        bitset<20000> b;
        b[0]=1;
        for(int& i : nums){
            b|=(b<<i);
        }
        if(b[sum] and b[sum/2]) return true;
        return false;
    }
};