class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<pair<int, int>> v(26, {-1, -1});
        for(int i = 0; i < n; i++){
            if(v[s[i] - 'a'].first == -1){
                v[s[i] - 'a'].first = i;
            }
            v[s[i] - 'a'].second = i;
        }
        vector<string> res;
        int lastRight = -1;
        for(int i = 0; i < n; i++){
            auto p = v[s[i]-'a'];
            if(i != p.first) continue;
            int j = p.first, last = p.second;
            while(j <= last){
                auto np = v[s[j] - 'a'];
                if(np.first < i){
                    last = -1;
                    break;
                }
                last = max(last, np.second);
                j++;
            }
            if(last == -1) continue;
            if(last > lastRight) res.push_back("");
            lastRight = last;
            res.back() = s.substr(i, last - i + 1);
        }
        return res;
    }
};