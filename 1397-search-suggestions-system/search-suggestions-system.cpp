class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        int n = products.size();
        vector<vector<string>> ans;
        int start = 0, end = n;
        string prefix;
        for(char& c:searchWord){
            prefix.push_back(c);
            int idx = lower_bound(products.begin()+start, products.end(),prefix) - products.begin();
            vector<string> results;
            for(int i = idx; i<min(idx+3,n) && products[i].substr(0, prefix.size()) == prefix; i++){
                results.push_back(products[i]);
            }
            ans.push_back(results);
            start = idx;
        }
        return ans;
    }
};