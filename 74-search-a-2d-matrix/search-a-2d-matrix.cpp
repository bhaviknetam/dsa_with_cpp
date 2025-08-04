class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int rl = 0, rh = n;
        while(rh - rl > 1){
            int mid = (rh + rl) / 2;
            if(matrix[mid][0] <= target){
                rl = mid;
            }else{
                rh = mid;
            }
        }
        // cout << rl << endl;
        int cl = 0, ch = m;
        while(ch - cl > 1){
            int mid = (ch + cl)/2;
            if(matrix[rl][mid] < target){
                cl = mid;
            }else if(matrix[rl][mid] > target){
                ch = mid;
            }else return true;
        }
        // cout << cl << endl;
        return (matrix[rl][cl] == target ? true : false);
    }
};