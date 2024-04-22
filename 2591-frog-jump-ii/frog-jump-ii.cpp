class Solution {
public:
    int maxJump(vector<int>& stones) {
        int ans = 0;
        int n = stones.size();
        if (n <= 1) return 0; 
        if (n == 2) return stones[1] - stones[0];
        int i = 2;
        while(i < n){
            ans = max(ans, stones[i] - stones[i-2]);
            i+=2;
        }
        if(i == n){
            i--;
            ans = max(ans, stones[i] - stones[i-2]);
        }else{
            i-=3;
        }
        while(i >= 2){
            ans = max(ans, stones[i] - stones[i-2]);
            i-=2;
        }
        if(i==1){
            ans = max(ans, stones[1] - stones[0]);
        }
        return ans;
    }
};