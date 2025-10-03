class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        int n = routes.size();
        unordered_map<int, vector<int>> adj;
        for(int i = 0; i < n; i++){
            for(int& path : routes[i]){
                adj[path].push_back(i);
            }
        }
        queue<pair<int, int>> q;
        vector<bool> vis(n);
        for(auto& bus : adj[source]){
            q.push({1, bus});
            vis[bus] = true;
        }
        while(!q.empty()){
            auto [ct, bus] = q.front();
            q.pop();
            for(int& path : routes[bus]){
                if(path == target) return ct;
                for(int& nextBus : adj[path]){
                    if(!vis[nextBus]){
                        vis[nextBus] = true;
                        q.push({ct + 1, nextBus});
                    }
                }
            }
        }
        return -1;
    }
};