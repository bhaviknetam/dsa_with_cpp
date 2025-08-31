class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        vector<int> l(n), r(n);
        stack<int> s;
        for(int i = 0 ;i < n; i++){
            while(!s.empty() && nums[i] <= nums[s.top()])
                s.pop();
            l[i] = (s.empty() ? -1 : s.top());
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i = n-1 ;i >= 0; i--){
            while(!s.empty() && nums[i] <= nums[s.top()])
                s.pop();
            r[i] = (s.empty() ? n : s.top());
            s.push(i);
        }
        vector<long long> pref(n);
        pref[0] = nums[0];
        for(int i = 1; i < n; i++){
            pref[i] = pref[i-1] + nums[i];
        }
        long long ans = 0;
        for(int i = 0 ; i< n; i++){
            long long sum = pref[r[i]-1] - (l[i]==-1 ? 0 : pref[l[i]]);
            // cout << l[i] <<' '<<r[i] <<  ' ' << sum<<';';
            ans = max(ans, nums[i] * 1LL * sum);
        }
        return ans % MOD;
    }
};