class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, unordered_set<string>> adj;
        unordered_set<string> vis;
        for (auto& acc : accounts) {
            string first = acc[1];
            for (int i = 2; i < acc.size(); i++) {
                adj[first].insert(acc[i]);
                adj[acc[i]].insert(first);
            }
        }
        function<void(string, vector<string>&)> dfs =
            [&](string node, vector<string>& store) {
                vis.insert(node);
                store.push_back(node);
                for (auto& neighbor : adj[node]) {
                    if (vis.find(neighbor) == vis.end()) {
                        dfs(neighbor, store);
                    }
                }
            };
        vector<vector<string>> mergedAccounts;
        for (auto& acc : accounts) {
            string name = acc[0];
            if (vis.find(acc[1]) == vis.end()) {
                vector<string> store;
                store.push_back(name);
                dfs(acc[1], store);
                sort(store.begin() + 1, store.end());
                mergedAccounts.push_back(store);
            }
        }
        return mergedAccounts;
    }
};