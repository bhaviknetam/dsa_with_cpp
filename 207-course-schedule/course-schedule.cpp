class Solution {
private:
    vector<int> color;
public:
    bool dfs(int node, vector<vector<int>>& adj){
        color[node] = 1;
        for(int& n : adj[node]){
            if(color[n] == 0 && !dfs(n, adj)){
                return false;
            }else if(color[n] == 1){
                return false;
            }
        }
        color[node] = 2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        color.assign(numCourses, 0);
        for(auto& v : prerequisites){
            if(v[0] != v[1])
                adj[v[1]].push_back(v[0]);
            else return false;
        }
        for(int i = 0; i < numCourses; i++){
            if(color[i] == 0 && !dfs(i, adj)){
                return false;
            }
        }
        return true;
    }
};