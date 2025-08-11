class Solution {
private: string ans;
         vector<int> fact;
public:
    void helper(int n, int k, set<int>& s){
        if(n == 0) return;
        int f = fact[n];
        int d = f / n;
        int q = k / d;
        k -= q * d;
        auto itr = next(s.begin(), q);
        ans.push_back(*itr + '0');
        s.erase(itr);
        helper(n - 1, k, s);
    }
    string getPermutation(int n, int k) {
        set<int> s;
        for(int i = 1; i <= n; i++) s.insert(i);
        fact.resize(n + 1, 1);
        for(int i = 2; i <=n; i++){
            fact[i] = i * fact[i-1];
        }
        helper(n, k - 1, s);
        return ans;
    }
};