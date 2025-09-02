class Solution {
public:
    struct PairHash{
        template<class T1, class T2>
        size_t operator()(const pair<T1, T2>& p) const{
            auto h1 = hash<T1>{}(p.first);
            auto h2 = hash<T2>{}(p.second);
            return h1 ^ (h2 << 1);
        }
    };

    unordered_map<pair<int, int>, int, PairHash> m;
    int func(int l, int r, vector<int>& cuts){
        if(m.find({l, r}) != m.end()) return m[{l, r}];
        int ans = INT_MAX;
        for(int& cut : cuts){
            if(cut > l && cut < r)
                ans = min(ans, r - l + func(l, cut, cuts) + func(cut, r, cuts));
        }
        return m[{l,r}] = (ans == INT_MAX ? 0 : ans);
    }
    int minCost(int n, vector<int>& cuts) {
        return func(0, n, cuts);
    }
};