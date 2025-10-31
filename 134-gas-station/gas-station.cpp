class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int currcost = 0, currgas = 0, start = 0;
        for(int i = 0; i < n; i++){
            currcost += (gas[i] - cost[i]);
            currgas += (gas[i] - cost[i]);
            if(currgas < 0){
                currgas = 0;
                start = i + 1;
            }
        }
        if(currcost >= 0) return start;
        return -1;
    }
};