class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<int> ans;
        int n = healths.size();
        vector<pair<int,int>> temp;
        map<int,pair<int,int>> m;
        for(int i=0;i<n;i++){
            healths[i] = (directions[i]=='R')?healths[i]:-healths[i];
            m[positions[i]]={i, healths[i]};
        }
        stack<pair<int,int>> s;
        for(auto& i : m){
            int index = i.second.first;
            int health = i.second.second;
            if(health > 0){
                s.push({index, health});
            }else{
                bool push = true;
                while(!s.empty()){
                    int top = s.top().second;
                    int topidx = s.top().first;
                    if(top > abs(health)){
                        int newhealth = top - 1;
                        s.pop();
                        s.push({topidx, newhealth});
                        break;
                    }else if(top < abs(health)){
                        health = (health<0)?health+1:health-1;
                        s.pop();
                        continue;
                    }else{
                        s.pop();
                        if(s.empty()) push = false;
                        break;
                    }
                }
                if(push and s.empty()){
                    temp.push_back({index, health});
                }
            }
        }
        while(!s.empty()){
            temp.push_back(s.top());
            s.pop();
        }
        sort(temp.begin(), temp.end());
        for(auto& i : temp){
            ans.push_back(abs(i.second));
        }
        return ans;
    }
};