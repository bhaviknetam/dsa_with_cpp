class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        auto can = [&](long long x, long long maxK){
            vector<long long> s(stations.begin(), stations.end());
            long long currPower = 0;
            for(int i = 0; i <= r; i++){
                currPower += s[i];
            }
            if(currPower < x){
                maxK -= (x - currPower);
                if(maxK < 0) return false;
                s[r] += (x - currPower);
                currPower = x;
            }
            for(int i = 1; i < n; i++){
                int prev = (i-r-1) >= 0 ? s[i-r-1] : 0;
                int next = (i+r) < n ? s[i+r] : 0;
                currPower -= prev;
                currPower += next;
                if(currPower < x){
                    maxK -= (x - currPower);
                    if(maxK < 0) return false;
                    int pos=min(n-1, i+r);
                    s[pos] += (x - currPower);
                    currPower = x;
                }
            }
            return true;
        };
        long long lo = 0, hi = accumulate(stations.begin(),stations.end(),0LL) + k;
        while(lo <= hi){
            long long mid = lo + (hi - lo)/2;
            if(can(mid, k)) lo = mid + 1;
            else hi = mid - 1;
        }
        return hi;
    }
};