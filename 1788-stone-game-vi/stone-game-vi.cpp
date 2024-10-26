class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<pair<int, int>> pq;
        for(int i = 0; i < n; i++){
            pq.push_back({aliceValues[i]+bobValues[i], i});
        }
        sort(pq.begin(), pq.end(), greater<pair<int, int>>());
        bool isAlice = true;
        int alice = 0, bob = 0, i = 0;
        while(i < n){
            if(isAlice){
                alice += aliceValues[pq[i].second];
            }else{
                bob += bobValues[pq[i].second];
            }
            isAlice = !isAlice;
            i++;
        }
        if(alice > bob) return 1;
        else if(alice < bob) return -1;
        else return 0;
    }
};