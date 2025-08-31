class Solution {
public:
    void dfs(int node, vector<bool>& vis, vector<int>& order, vector<vector<int>>& adj){
        vis[node] = true;
        for(int& v : adj[node]){
            if(!vis[v])
                dfs(v, vis, order, adj);
        }
        order.push_back(node);
    }
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        const int ALPHA = 26;
        vector<int> first(26, 1e6), last(26, -1);
        for(int i =0 ;i < n; i++){
            int j = s[i] - 'a';
            first[j] = min(first[j], i);
            last[j] = max(last[j], i);
        }
        vector<vector<int>> adj(ALPHA), radj(ALPHA);
        for (int u = 0; u < ALPHA; u++) {
            if (last[u] == -1) continue;
            int start = first[u], end = last[u];
            vector<bool> seen(ALPHA, false);
            for (int i = start; i <= end; i++) {
                int v = s[i] - 'a';
                if (v != u && !seen[v]) {
                    adj[u].push_back(v);
                    radj[v].push_back(u);
                    seen[v] = true;
                }
            }
        }
        vector<bool> vis(26, false);
        vector<int> order;
        for(int u = 0; u < 26; u++){
            if(last[u] != -1 && !vis[u]){
                dfs(u, vis, order, adj);
            }
        }
        vector<int> compId(26, -1);
        reverse(order.begin(), order.end());
        vis.assign(26, false);
        int id = 0;
        for(int& u : order){
            if(!vis[u]){
                vector<int> comp;
                dfs(u, vis, comp, radj);
                for(int& v : comp){
                    compId[v] = id;
                }
                id++;
            }
        }
        vector<int> sccOut(id, 0);
        for(int u = 0; u < 26; u++){
            if(last[u] == -1) continue;
            for(int& v : adj[u]){
                if(compId[v] != compId[u]){
                    sccOut[compId[u]]++;
                }
            }
        }
        vector<int> sccfirst(id, 1e6), scclast(id, -1);
        for(int u = 0; u < 26; u++){
            if(last[u] == -1) continue;
            int cid = compId[u];
            sccfirst[cid] = min(sccfirst[cid], first[u]);
            scclast[cid] = max(scclast[cid], last[u]);
        }
        vector<string> ans;
        for(int i = 0; i < id; i++){
            if(sccOut[i] == 0)
            ans.push_back(s.substr(sccfirst[i], scclast[i]-sccfirst[i]+1));
        }
        return ans;
    }
};