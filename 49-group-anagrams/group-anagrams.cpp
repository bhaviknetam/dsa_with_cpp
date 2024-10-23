class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for(auto& str : strs){
            vector<int> vec(26, 0);
            for(char& c: str){
                vec[c-'a']++;
            }
            string s;
            for(int i = 0; i < 26; i++) s.push_back(vec[i] + '0');
            m[s].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto it : m){
            ans.push_back(it.second);
        }
        return ans;
    }
};