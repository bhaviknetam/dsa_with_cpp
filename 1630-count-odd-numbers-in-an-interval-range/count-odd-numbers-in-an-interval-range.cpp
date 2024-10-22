class Solution {
public:
    int countOdds(int low, int high) {
        int lo = low, hi = high;
        int ans = (high - low + 1)-((int)high/2 - (int)(low + 1)/2 + 1);
        return ans;
    }
};