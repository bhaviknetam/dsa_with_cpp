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
                if(i == 0){
                    median = nums2[j - 1];
                }else if(j == 0){
                    median = nums1[i - 1];
                }else{
                    median = max(nums1[i - 1], nums2[j - 1]);
                }
                break;
            }
        }
        if((n + m) & 1) return (double)median;
        if(i == n) return (median + nums2[j])/2.0;
        if(j == m) return (median + nums1[i])/2.0;
        return (median + min(nums1[i], nums2[j]))/2.0;
    }
};