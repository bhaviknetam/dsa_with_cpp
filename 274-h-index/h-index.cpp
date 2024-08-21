class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        auto ok = [&](int x) {
            int count = 0;
            for (int i = 0; i < n; i++) {
                if (citations[i] >= x) {
                    count++;
                }
            }
            return count >= x;
        };
        int lo = 0, hi = 1000;
        while (hi - lo > 1) {
            int mid = (lo + hi) / 2;
            if (ok(mid))
                lo = mid;
            else
                hi = mid - 1;
        }
        if (ok(hi))
            return hi;
        return lo;
    }
};