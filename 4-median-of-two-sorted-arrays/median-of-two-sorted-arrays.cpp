class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1 > n2) swap(nums1, nums2), swap(n1, n2);
        int n = n1 + n2;
        int left = (n+1)/2;
        int lo = 0, hi = n1;
        while(lo <= hi){
            int mid1 = (lo+hi)>>1;
            int mid2 = left-mid1;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if(mid1 >= 1) l1 = nums1[mid1-1];
            if(mid1 < n1) r1 = nums1[mid1];
            if(mid2 >= 1) l2 = nums2[mid2-1];
            if(mid2 < n2) r2 = nums2[mid2];
            if(l1 > r2) hi = mid1-1;
            else if(l2 > r1) lo = mid1+1;
            else{
              return (n & 1)?max(l1, l2):(max(l1, l2)+min(r1,r2))/2.0;
            }
        }
        return 0;
    }
};