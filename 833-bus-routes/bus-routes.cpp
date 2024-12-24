class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source,
                              int target) {
        if (source == target)
            return 0;
        int n = routes.size();
        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < n; i++) {
            for (int& stops : routes[i]) {
                graph[stops].push_back(i);
            }
        }
        queue<pair<int, int>> q;
        vector<int> vis(n, false);
        for (int& bus : graph[source]) {
            q.push({bus, 1});
            vis[bus] = true;
        }
        unordered_set<int> visStops;
        while (!q.empty()) {
            int bus = q.front().first;
            int busCount = q.front().second;
            q.pop();
            for (int& nextStop : routes[bus]) {
                if(nextStop == target) return busCount;
                if (visStops.count(nextStop))
                    continue;
                for (int& nextBus : graph[nextStop]) {
                    if (!vis[nextBus]) {
                        vis[nextBus] = true;
                        q.push({nextBus, busCount + 1});
                    }
                }
            }
        }
        return -1;
    }
};