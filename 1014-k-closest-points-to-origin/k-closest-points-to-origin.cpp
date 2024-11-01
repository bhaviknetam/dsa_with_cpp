class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<long long, pair<int, int>>> v;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            long long val = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            v.push_back({val,{points[i][0],points[i][1]}});
        }
        sort(v.begin(), v.end());
        vector<vector<int>> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back({v[i].second.first, v[i].second.second});
        }
        return ans;
    }
};