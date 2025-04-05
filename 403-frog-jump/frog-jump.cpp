class Solution {
private:
    unordered_map<int, int> m;
    vector<vector<int>> dp;
public:
    bool func(int i, int k, vector<int>& stones){
        if(i == stones.size() - 1) return true;
        if(dp[i][k] != -1) return dp[i][k];
        bool ans = false;
        if(k - 1 > 0 && m.count(stones[i] + k - 1)){
            ans|=func(m[stones[i] + k - 1], k - 1, stones);
        }
        if(m.count(stones[i] + k)){
            ans|=func(m[stones[i] + k], k, stones);
        }
        if(m.count(stones[i] + k + 1)){
            ans|=func(m[stones[i] + k + 1], k + 1, stones);
        }
        return dp[i][k] = ans;
    }

    bool canCross(vector<int>& stones) {
        if(stones[1] != 1) return false;
        dp.resize(stones.size() + 1, vector<int>(stones.size() + 1, -1));
        for(int i = 0; i < stones.size(); i++){
            m[stones[i]] = i;
        }
        return func(1, 1, stones);
    }
};