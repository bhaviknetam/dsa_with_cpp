class Solution {
private: unordered_map<string, int> emailPar;
        vector<int> par;
public:
    void init(int n){
        for(int i = 0; i < n; i++){
            par[i] = i;
        }
    }
    
    int find(int x){
        while(x!=par[x]){
            par[x] = par[par[x]];
            x = par[x];
        }
        return x;
    }

    void Union(int a, int b){
        a = find(a);
        b = find(b);
        if(a != b) par[a] = par[b];
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        par.resize(n, 0);
        init(n);
        for(int i = 0; i < n;  i++){
            for(int j = 1; j < accounts[i].size(); j++){
                if(emailPar.find(accounts[i][j]) == emailPar.end())
                    emailPar[accounts[i][j]] = i;
                else{
                    Union(par[i], emailPar[accounts[i][j]]);
                }
            }
        }
        vector<set<string>> v(n);
        for(auto it : emailPar){
            v[find(it.second)].insert(it.first);
        }
        vector<vector<string>> mergedAccs;
        for(int i = 0; i <n; i++){
            if(v[i].empty())continue;
            vector<string> mergedAcc;
            mergedAcc.push_back(accounts[i][0]);
            for(auto& str : v[i]){
                mergedAcc.push_back(str);
            }
            mergedAccs.push_back(mergedAcc);
        }
        return mergedAccs;
    }
};