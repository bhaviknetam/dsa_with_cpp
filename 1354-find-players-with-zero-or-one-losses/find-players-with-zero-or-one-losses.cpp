class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> m;
        set<int> s;
        vector<vector<int>> v(2);
        for(int i =0; i< matches.size(); i++){
            m[matches[i][1]]++;
            s.insert(matches[i][0]);
        }
        for(auto it : s){
            if(m.find(it) == m.end()) v[0].push_back(it);
        }
        for(auto it : m){
            if(it.second == 1) v[1].push_back(it.first);
        }
        return v;
    }
};