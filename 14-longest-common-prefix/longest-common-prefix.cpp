class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;        
        int maxSize = INT_MAX;
        for(auto& str : strs){
            maxSize = min(maxSize, (int)str.size());
        }
        for(int i = 0; i < maxSize; i++){
            unordered_set<char> s;
            for(auto& str:strs){
                s.insert(str[i]);
            }
            if(s.size() == 1) ans.push_back(*s.begin());
            else break;
        }
        return ans;
    }
};