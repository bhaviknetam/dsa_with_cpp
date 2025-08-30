class Solution {
private:
    vector<int> color;
public:
    bool dfs(int node, vector<vector<int>>& graph){
        for(int& n : graph[node]){
            if(color[n] == -1){
                color[n] = !color[node];
                if(!dfs(n, graph)) return false;
            }else if(color[n] == color[node]){
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        color.assign(graph.size(), -1);
        for(int i = 0; i < graph.size(); i++){
            if(color[i] == -1){
                color[i] = 0;
                if(!dfs(i, graph)) return false;
            }
        }
        return true;
    }
};