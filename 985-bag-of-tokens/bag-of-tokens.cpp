class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int  n = tokens.size();
        int score=0;
        int i=0,j=n-1;
        //int vis[n];
        if(n==0) return 0;
        while(i<=j){
            if(tokens[i] <= power){
                power-=tokens[i];
                score++;
               // vis[i]=1;
                i++;
            }
           else if(score>0 and i<j){
               score--;
               power+=tokens[j];
               j--;
           }
           else return score;
        }
        return score;
    }
};