struct Fenwick{
    vector<int> bit;
    int n;
    Fenwick(int _n) : n(_n+1){
        bit.assign(n+1, 0);
    }
    void add(int idx, int delta){
        for(;idx < n; idx += idx & -idx){
            bit[idx] += delta;
        }
    }
    int sum(int idx){
        int res = 0;
        for(;idx > 0; idx -= idx & -idx){
            res += bit[idx];
        }
        return res;
    }
    int sum(int l, int r){
        if(l > r) return 0;
        return sum(r) - sum(l-1);
    }
};

class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](auto& a, auto& b){
            if(a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });

        int maxEnd = tasks.back()[1];
        Fenwick fw(maxEnd + 2);

        for(auto& task : tasks){
            int start = task[0], end = task[1], duration = task[2];
            duration -= fw.sum(start, end);

            for (int t = end; duration > 0; --t) {
                if (fw.sum(t, t) == 0) {
                    fw.add(t, 1);
                    duration--;
                }
            }
        }
        return fw.sum(maxEnd);
    }
};