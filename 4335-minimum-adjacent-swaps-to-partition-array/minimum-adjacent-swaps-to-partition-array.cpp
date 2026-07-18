class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        vector<int> newVec;
        int curridx = 0;
        long long ans = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] < a){
                ans += i - curridx;
                curridx++;
            }else{
                newVec.push_back(nums[i]);
            }
        }
        int m = newVec.size(); curridx = 0;
        // cout << m <<' ' << ans << ' ';
        for(int i = 0; i < m; i++){
            if(newVec[i] >= a && newVec[i] <= b){
                ans += i - curridx;
                curridx++;
            }
        }
        ans = ans % MOD;
        return (int)ans;
    }
};