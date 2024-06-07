class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char, int> m;
        for (char& c : words[0]) {
            m[c]++;
        }
        for (int i = 1; i < words.size(); i++) {
            unordered_map<char, int> temp;
            for (char& c : words[i]) {
                auto it = m.find(c);
                if (it != m.end()) {
                    temp[c]++;
                    it->second--;
                    if (it->second == 0) {
                        m.erase(it);
                    }
                }
            }
            swap(m, temp);
            
        }
        vector<string> ans;
        for (auto& it : m) {
            while(it.second--)  // Change to directly initialize the string with the character
            ans.push_back(string(1,it.first));
        }
        return ans;
    }
};
