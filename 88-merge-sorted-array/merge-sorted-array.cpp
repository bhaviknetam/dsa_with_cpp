class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int r1 = m -1, r2 = n-1;
        for(int i = n +m-1;i>=0;i--){
            if(r1 >=0 and r2 >=0)
            nums1[i] = (nums1[r1] > nums2[r2]) ? nums1[r1--] : nums2[r2--];
            else if(r1 >= 0){
                nums1[i] = nums1[r1--];
            }
            else if(r2 >= 0){
                nums1[i] = nums2[r2--];
            }
            
        }
    }
};