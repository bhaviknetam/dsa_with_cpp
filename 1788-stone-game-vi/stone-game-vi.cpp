class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < n; i++){
            pq.push({aliceValues[i]+bobValues[i], i});
        }
        bool isAlice = true;
        int alice = 0, bob = 0;
        while(!pq.empty()){
            if(isAlice){
                alice += aliceValues[pq.top().second];
            }else{
                bob += bobValues[pq.top().second];
            }
            pq.pop();
            isAlice = !isAlice;
        }
        if(alice > bob) return 1;
        else if(alice < bob) return -1;
        else return 0;
    }
};