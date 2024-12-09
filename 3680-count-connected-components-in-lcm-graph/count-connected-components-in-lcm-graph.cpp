class Solution {
private:
    unordered_set<int> s;
    unordered_map<int, int> parent;

public:
    int find(int x) {
        if(parent.find(x) == parent.end()) return x;
        while (x != parent[x]) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    void Union(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (s.count(a) && s.count(b)) {
                parent[max(a, b)] = min(a, b);
                return;
            }
            if (s.find(a) == s.end())
                swap(a, b);
            parent[b] = a;
        }
    }
    int countComponents(vector<int>& nums, int threshold) {
        for (int& num : nums)
            s.insert(num), parent[num] = num;
        for(int& num:nums){
            for(int i = 2*num; i <= threshold; i += num){
                Union(num, i);
            }
        }
        unordered_set<int> ans;
        for(int &num:nums){
            ans.insert(find(num));
        }
        return ans.size();
    }
};