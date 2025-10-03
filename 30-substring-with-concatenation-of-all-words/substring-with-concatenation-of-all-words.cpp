class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        int k = words[0].size();
        int m = words.size();
        unordered_map<string, int> wordsMap;
        for (auto& word : words) {
            wordsMap[word]++;
        }
        int len = m * k;
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            unordered_map<string, int> windowMap;
            int left = i, j = i;
            for (; j + k <= n; j += k) {
                string t = s.substr(j, k);
                if (wordsMap.find(t) == wordsMap.end()) {
                    windowMap.clear();
                    left = j + k;
                    continue;
                }
                windowMap[t]++;
                while (windowMap[t] > wordsMap[t]) {
                    string rem = s.substr(left, k);
                    windowMap[rem]--;
                    if (windowMap[rem] == 0)
                        windowMap.erase(rem);
                    left += k;
                }
                if (j - left + k == len) {
                    ans.push_back(left);
                }
            }
        }
        return ans;
    }
};