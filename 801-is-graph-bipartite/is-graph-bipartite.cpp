class Solution {
private:
    vector<int> color;
public:
    bool bfs(int node, vector<vector<int>>& graph){
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int n = q.front();
            q.pop();
            for(int& child : graph[n]){
                if(color[child] == -1){
                    color[child] = !color[n];
                    q.push(child);
                }else if(color[child] == color[n]){
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        color.assign(graph.size(), -1);
        for(int i = 0; i < graph.size(); i++){
            if(color[i] == -1){
                color[i] = 0;
                if(!bfs(i, graph)) return false;
            }
        }
        return true;
    }
};