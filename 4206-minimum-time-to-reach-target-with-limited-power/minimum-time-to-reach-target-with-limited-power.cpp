using ll = long long;
class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges,
                                      int power, vector<int>& cost, int source,
                                      int target) {
        vector<pair<int, int>> adj[n];
        int m = edges.size();
        for (int i = 0; i < m; i++) {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }

        auto compare = [](pair<int, pair<ll, ll>> a,
                          pair<int, pair<ll, ll>> b) {
            if (a.second.first == b.second.first)
                return a.second.second < b.second.second;
            return a.second.first > b.second.first;
        };

        priority_queue<pair<int, pair<ll, ll>>, vector<pair<int, pair<ll, ll>>>,
                       decltype(compare)> pq;
        pq.push({source, {0, power}});
        vector<ll> minTime(n, LLONG_MAX), maxPow(n, LLONG_MIN);
        minTime[source] = 0, maxPow[source] = power;
        while (!pq.empty()) {
            auto [u, tp] = pq.top();
            auto [time, currPow] = tp;
            pq.pop();
            if(u == target) return {time, currPow};
            if(time > minTime[u] && currPow <= maxPow[u]) continue;
            if(u!=source && time == minTime[u] && currPow <= maxPow[u]) continue;
            minTime[u] = min(minTime[u], time);
            maxPow[u] = max(maxPow[u], currPow);
            ll newPower = currPow - cost[u];
            if(newPower < 0) continue;
            for (auto& [v, t] : adj[u]) {
                ll newTime = time + t;
                if ((minTime[v] > newTime) || (maxPow[v] < newPower)) {
                    pq.push({v, {newTime, newPower}});
                }
            }
        }
        return {-1, -1};
    }
};