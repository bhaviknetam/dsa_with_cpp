class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](auto& a, auto& b){
            if(a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });
        int n = tasks.size();
        vector<bool> timeSlots(tasks[n-1][1] + 2, false);
        for(auto& task : tasks){
            int start = task[0], end = task[1], duration = task[2];
            for(int i = start; i <= end; i++){
                if(timeSlots[i]) duration--;
            }
            int t = end;
            while(duration > 0){
                if(!timeSlots[t]){
                    timeSlots[t] = true;
                    duration--;
                }
                t--;
            }
        }
        return accumulate(timeSlots.begin(), timeSlots.end(), 0);
    }
};