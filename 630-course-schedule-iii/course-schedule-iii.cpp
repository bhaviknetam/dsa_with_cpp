class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        sort(courses.begin(), courses.end(), [&](auto a, auto b){
            if(a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });
        priority_queue<int> pq;
        int time = 0;
        for(int i = 0; i < n; i++){
            if(time + courses[i][0] <= courses[i][1]){
                pq.push(courses[i][0]);
                time += courses[i][0];
            }else{
                if(pq.empty()) continue;
                if(courses[i][0] < pq.top()){
                    time -= pq.top();
                    pq.pop();
                    pq.push(courses[i][0]);
                    time += courses[i][0];
                }
            }
        }
        return pq.size();
    }
};