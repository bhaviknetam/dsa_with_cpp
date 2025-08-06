class Fenwick {
private:
    vector<int> bit;
    int n;

public:
    Fenwick(int _n) : n(_n), bit(_n, 0) {}

    int sum(int r) {
        int ans = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            ans += bit[r];
        }
        return ans;
    }

    int sum(int l, int r) { return sum(r) - sum(l - 1); }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1)) {
            bit[idx] += delta;
        }
    }
    void print() {
        for (int i = 0; i < n; i++)
            cout << bit[i] << ';';
    }
};

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int id = 0;
        map<long long, int> m;
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        for (int& num : temp) {
            if (m.find(num) == m.end())
                m[num] = id++;
        }
        auto bit = Fenwick(id + 1);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            long long val = 2LL * nums[i];
            auto ptr = m.upper_bound(val);
            if (ptr != m.end()) {
                ans += bit.sum(ptr->second, id);
            }
            bit.add(m[nums[i]], 1);
        }
        return ans;
    }
};