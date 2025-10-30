class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int> s;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            while(!s.empty() && (s.size()+n-i>k) && s.top() > nums[i]){
                s.pop();
            }
            s.push(nums[i]);
        }
        while(s.size() > k) s.pop();
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};