class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        for(int val : nums2){
            nums1.push_back(val);
        }
        sort(nums1.begin(), nums1.end());
        int n = n1 + n2;
        return (n&1)?nums1[n/2]:(nums1[n/2]+nums1[n/2 - 1])/2.0;
    }
};