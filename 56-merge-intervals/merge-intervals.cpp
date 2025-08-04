class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int i = 0;
        vector<vector<int>> ans;
        while(i < n){
            int j = i + 1;
            int end = intervals[i][1];
            while(j < n && end >= intervals[j][0]){
                end = max(end, intervals[j][1]);
                j++;
            }
            ans.push_back({intervals[i][0], end});
            i = j;
        }
        return ans;
    }
};