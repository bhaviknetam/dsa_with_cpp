class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> l(n), r(n);
        stack<int> s;
        for(int i = 0; i < n; i++){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            l[i] = (s.empty() ? -1 : s.top());
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i = n - 1; i >= 0; i--){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            r[i] = (s.empty() ? n : s.top());
            s.push(i);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            // cout << l[i]<<' '<<r[i]<<';';
            ans = max(ans, (r[i] - l[i] - 1) * heights[i]);
        }
        return ans;
    }
};