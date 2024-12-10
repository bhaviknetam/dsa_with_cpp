class Solution {
private:
    unordered_set<int> s;
    vector<int> parent;

public:
    int find(int x) {
        while(x != parent[x]){
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    void Union(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if(s.find(a) != s.end() && s.find(b) != s.end())
                if (a > b)
                    swap(a, b);
            else if(s.find(a) != s.end()){
                swap(a, b);
            }
            parent[b] = a;
        }
    }
    int countComponents(vector<int>& nums, int threshold) {
        parent.resize(threshold+1);
        for(int i = 0; i <= threshold; i++) parent[i] = i;
        int mini = INT_MAX;
        for (int& num : nums)
            s.insert(num), mini = min(mini, num);
        for(int i = mini; i <= threshold; i++){
            for(int j = 1; j * j <= i; j++){
                if(i % j == 0){
                    if(s.find(j) != s.end())
                        Union(j, i);
                    if(i/j != j && s.find(i/j) != s.end())
                        Union(i/j, i);
                }
            }
        }
        unordered_set<int> ans;
        for(int &num:nums){
            if(num <= threshold)
                ans.insert(find(num));
            else ans.insert(num);
        }
        return ans.size();
    }
};