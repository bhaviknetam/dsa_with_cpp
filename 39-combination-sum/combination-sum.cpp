class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<bool> present(target + 1, false);
        vector<vector<vector<int>>> store(target + 1);
        for (int& val : candidates)
            if (val <= target)
                present[val] = true, store[val].push_back({{val}});
        for (int i = 1; i <= target; i++) {
            if (!present[i])
                continue;
            auto t = store[i];
            for (auto& v : t) {
                int last = v.back();
                for (int& c : candidates) {
                    if (c < last)
                        continue;
                    if(i + c > target) continue;
                    present[i + c] = true;
                    vector<int> p = v;
                    p.push_back(c);
                    store[i + c].push_back(p);
                }
            }
        }
        return store[target];
    }
};