class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<pair<int, pair<char, pair<int, int>>>> info;
        int n = positions.size();
        for(int i = 0; i < n; i++){
            info.push_back({positions[i], {directions[i], {healths[i], i}}});
        }
        sort(info.begin(), info.end());
        cout << info.size() << endl;
        stack<pair<char, pair<int, int>>> s;
        for(auto& vals : info){
            char dir = vals.second.first;
            int currH = vals.second.second.first;
            int idx = vals.second.second.second;
            bool flag = false;
            while(!s.empty() && s.top().first == 'R' && dir == 'L'){
                int& prevH = s.top().second.first;
                if(prevH > currH){
                    prevH = prevH - 1;
                    flag = true;
                    break;
                }else if(currH > prevH){
                    s.pop();
                    currH = currH - 1;
                }else{
                    s.pop();
                    flag = true;
                    break;
                }
            }
            if(!flag) s.push({dir, {currH, idx}});
        }
        vector<int> ans(n, -1);
        while(!s.empty()){
            auto& [dir, curr] = s.top();
            ans[curr.second] = curr.first;
            s.pop();
        }
        vector<int> res;
        for(int i = 0; i < n; i++)
            if(ans[i] != -1) res.push_back(ans[i]);
        
        return res;
    }
};