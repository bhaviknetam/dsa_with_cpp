class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> move_right, temp;
        int n= asteroids.size();
        for(int i = 0; i < n;i++){
            if(asteroids[i] > 0){
                move_right.push(asteroids[i]);
            }
            else{
                bool push = true;
                while(!move_right.empty()){
                    int store = move_right.top();
                    if(store > abs(asteroids[i])){
                        break;
                    }else if(move_right.top() < abs(asteroids[i])){
                        move_right.pop();
                    }else{
                        move_right.pop();
                        if(move_right.empty()){
                            push=false;
                        }
                        break;
                    }
                }
                if(push and move_right.empty()){
                    ans.push_back(asteroids[i]);
                }

            }
        }
        while(!move_right.empty()){
            temp.push(move_right.top());
            move_right.pop();
        }
        while(!temp.empty()){
            ans.push_back(temp.top());
            temp.pop();
        }
        return ans;
    }
};