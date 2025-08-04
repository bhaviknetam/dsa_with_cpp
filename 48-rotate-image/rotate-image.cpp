class Solution {
public:
    void reverse(vector<int>& nums){
        int s = 0, e = nums.size()-1;
        while(s < e){
            swap(nums[s],nums[e]);
            s++;
            e--;
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i = 0; i<n;i++){
            for(int j=i;j<n;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0; i < n; i++){
            reverse(matrix[i]);
        }
    }
};