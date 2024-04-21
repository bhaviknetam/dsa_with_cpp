class Solution {
public:
    bool dfs(vector<int>graph[],vector<bool>& vis, int source, int destination){
        if(source == destination) return true;
        if(vis[source]) return false;
        vis[source]=true;
        for(int& edge : graph[source]){
            if(dfs(graph, vis, edge, destination)) return true;
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> graph[n];
        vector<bool> vis(n, false);
        for(auto& edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        return dfs(graph,vis, source, destination);
    }
};