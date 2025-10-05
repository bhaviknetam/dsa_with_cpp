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
            time += courses[i][0];
            pq.push(courses[i][0]);
            if(time > courses[i][1]){
                time -= pq.top(); pq.pop();
            }
        }
        return pq.size();
    }
};