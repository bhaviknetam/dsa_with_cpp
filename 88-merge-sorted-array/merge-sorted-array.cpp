class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        multiset<int> s;
        while (n--) {
            nums1.pop_back();
        }
        for (auto i : nums1) {

            s.insert(i);
        }
        for (auto i : nums2) {
            s.insert(i);
        }
        // nums1.clear();
        nums1 = {s.begin(), s.end()};
    }
};