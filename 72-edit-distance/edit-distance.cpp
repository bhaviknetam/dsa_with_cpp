class Solution {
private:
    vector<vector<int>> dp;
public:
    int func(int i, int j, string& word1, string& word2){
        if(j == word2.size() && i == word1.size()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = 0;
        if(j >= word2.size()){
            ans = 1 + func(i+1, j, word1, word2);
        }else if(i >= word1.size()){
            ans = 1 + func(i, j + 1, word1, word2);
        }else if(word1[i] != word2[j]){
            ans = 1 + min({func(i, j + 1, word1, word2),func(i+1, j+1, word1, word2), func(i+1, j, word1, word2)});
        }else{
            ans = func(i+1, j+1, word1, word2);
        }
        return dp[i][j] = ans;
    }
    int minDistance(string word1, string word2) {
        if(word1.size() > word2.size()) 
            return minDistance(word2, word1);
        dp.assign(word1.size() + 1, vector<int>(word2.size() + 1, -1));
        return func(0, 0, word1, word2);
    }
};