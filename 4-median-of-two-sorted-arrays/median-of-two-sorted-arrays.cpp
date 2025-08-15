class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size();
        int m = nums2.size();
        if(n > m) return findMedianSortedArrays(nums2, nums1);
        int midIdx = (n + m + 1) / 2;
        int lo = 0, hi = n , i, j, median;
        while(lo <= hi){
            i = ((lo + hi) >> 1);
            j = midIdx - i;
            if(j < 0){
                hi = i - 1;
                continue;
            }
            if(i < n && j > 0 && nums2[j - 1] > nums1[i]){
                lo = i + 1;
            }else if(j < m && i > 0 && nums2[j] < nums1[i - 1]){
                hi = i - 1;
            }else{
                int l1 = (i == 0) ? INT_MIN : nums1[i-1];
                int l2 = (j == 0) ? INT_MIN : nums2[j-1];
                if((n + m) & 1) return max(l1, l2);
                int r1 = (i < n) ? nums1[i] : INT_MAX;
                int r2 = (j < m) ? nums2[j] : INT_MAX;
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
        }
        return -1;
    }
};