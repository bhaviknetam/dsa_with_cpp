class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int> xorofnum(n+1,0);;
        for(int i=1;i<=n;i++){
            xorofnum[i]=xorofnum[i-1]^arr[i-1];
        }
        vector<int> ans;
        for(auto it : queries){
            int l=it[0], r=it[1];
            int num =xorofnum[r+1]^xorofnum[l];
            ans.push_back(num);
        }
        return ans;
    }
};