class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0, i=0;
        stack<int> s;
        while(i<height.size()){
            while(!s.empty() and height[i] > height[s.top()]){
                int top = s.top();
                s.pop();
                if(s.empty())break;
                int dist = i - s.top() -1;
                int store = min(height[i], height[s.top()]) - height[top];
                ans+=dist*store;
            }
            s.push(i);
            i++;
        }
        return ans;
    }
};