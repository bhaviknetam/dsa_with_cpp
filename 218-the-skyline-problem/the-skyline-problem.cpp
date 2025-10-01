class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();
        set<int> edges;
        for(auto& v : buildings){
            edges.insert(v[0]);
            edges.insert(v[1]);
        }
        vector<int> edgeSet(edges.begin(), edges.end());
        unordered_map<int, int> mp;
        int sz = 0;
        for(auto &val : edgeSet){
            mp[val] = sz;
            sz++;
        }
        vector<vector<int>> heights(sz, vector<int>());
        for(int i = 0; i < n; i++){
            int l = buildings[i][0];
            int r = buildings[i][1];
            int h = buildings[i][2];
            heights[mp[l]].push_back(h);
            heights[mp[r]].push_back(-h);
        }
        map<int, int> m;
        int prev = -1;
        vector<vector<int>> ans;
        for(int i = 0; i < sz; i++){
            for(int& h : heights[i]){
                if(h > 0) m[h]++;
                else{
                    m[-h]--;
                    if(m[-h] == 0) m.erase(-h);
                }
            }
            int curr = (m.empty() ? 0 : m.rbegin()->first);
            // cout << curr << ' ';
            if(curr != prev){
                ans.push_back({edgeSet[i], curr});
                prev = curr;
            }
        }
        return ans;
    }
};