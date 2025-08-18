class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> next;
        for(int i = nums2.size() - 1; i >= 0; --i){
            while(!s.empty() && nums2[i] > s.top()){
                s.pop();
            }
            if(s.empty()) next[nums2[i]] = -1;
            else next[nums2[i]] = s.top();
            s.push(nums2[i]);
        }
        vector<int> ans;
        for(int& num : nums1){
            ans.push_back(next[num]);
        }
        return ans;
    }
};