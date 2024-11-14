class Solution {
private:
    vector<vector<int>> adj;
    vector<int> ans;
public:
    vector<int> dfs(int node, int par, string& label){
        vector<int> temp(26, 0);
        temp[label[node] - 'a']++;
        for(int& child : adj[node]){
            if(child != par){
                vector<int> v = dfs(child, node, label);
                for(int i = 0; i < 26; i++){
                    temp[i] += v[i];
                }
            }
        }
        ans[node] = temp[label[node]-'a'];
        return temp;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        adj.resize(n);
        ans.resize(n);
        for(auto& node : edges){
            adj[node[0]].push_back(node[1]);
            adj[node[1]].push_back(node[0]);
        }
        dfs(0, -1, labels);
        return ans;
    }
};