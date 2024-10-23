class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> m;
        for(auto& str : strs){
            vector<int> vec(26, 0);
            for(char& c: str){
                vec[c-'a']++;
            }
            m[vec].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto it : m){
            ans.push_back(it.second);
        }
        return ans;
    }
};