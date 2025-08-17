class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            m[nums[i]]++;
        }
        vector<vector<int>> buckets(n + 1);
        for(auto& [num, freq] : m){
            cout << num << ' ' << freq << endl;
            buckets[freq].push_back(num);
        }
        vector<int> ans;
        for(int i = n; i >= 0; i--){
            for(int j = 0; j < buckets[i].size(); j++){
                ans.push_back(buckets[i][j]);
                if(ans.size() == k) return ans;
            }
        }
        return ans;
    }
};