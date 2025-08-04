class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int e1 = m - 1, e2 = n - 1, l1 = m + n - 1;
        while(e2 >= 0){
            if(e1 >= 0 and nums1[e1] > nums2[e2]){
                nums1[l1] = nums1[e1];
                e1--;
            }else{
                nums1[l1] = nums2[e2];
                e2--;
            }
            l1--;
        }
    }
};