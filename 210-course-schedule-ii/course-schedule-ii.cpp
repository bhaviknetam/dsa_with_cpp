class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int m = prerequisites.size();
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);
        for(auto& v : prerequisites){
            adj[v[1]].push_back(v[0]);
            inDegree[v[0]]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int u = q.front(); q.pop();
            ans.push_back(u);
            for(int& v : adj[u]){
                inDegree[v]--;
                if(inDegree[v] == 0) q.push(v);
            }
        }
        if(ans.size() != numCourses) return {};
        return ans;
    }
};