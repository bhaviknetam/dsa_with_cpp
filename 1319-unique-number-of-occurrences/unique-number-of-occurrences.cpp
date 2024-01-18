class Solution {
public:
    const int N= 1e5;
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> v;
        //int n = arr.size();
        int vis[N];
        for(int i = 0; i <  N; i++){
            vis[i] = 0;
        }
        for(auto it : arr){
            v[it]++;
        }
        for(auto it : v){
            if(vis[it.second]==1) return false;
            vis[it.second] = 1;
        }
        return true;
    }
};
