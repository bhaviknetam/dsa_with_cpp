class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int i = 0;
        vector<vector<int>> ans;
        while(i < n){
            int j = i + 1;
            int maxval = intervals[i][1];
            while(j < n and intervals[j][0] <= maxval){
                maxval = max(maxval,  intervals[j][1]);
                j++;
            }
            ans.push_back({intervals[i][0], maxval});
            i = j;
        }
        return ans;
    }
};