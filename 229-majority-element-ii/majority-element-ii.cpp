class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ct1 = 0, ct2 = 0, cd1 = 0, cd2 = 1;
        for (int& num : nums) {
            if(num == cd1) ct1++;
            else if(num == cd2) ct2++;
            else if(ct1 == 0) cd1 = num, ct1 = 1;
            else if(ct2 == 0) cd2 = num, ct2 = 1;
            else ct1--, ct2--;
        }
        // cout << cd2 <<';';
        ct1 = ct2 = 0;
        for (int num : nums) {
            if (num == cd1) {
                ct1++;
            }else if(num == cd2) {
                ct2++;
            }
        }
        int n = nums.size();
        vector<int> ans;
        if (ct1 > n / 3)
            ans.push_back(cd1);
        if (ct2 > n / 3)
            ans.push_back(cd2);
        // cout<< cd1<<';'<<cd2;
        return ans;
    }
};