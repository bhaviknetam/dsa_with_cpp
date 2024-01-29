class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int totalHammingDist = 0;
        
        // Iterate over each bit position
        for (int i = 0; i < 32; ++i) {
            int countSetBits = 0;
            
            // Count the number of set bits at the current position
            for (int num : nums) {
                countSetBits += (num >> i) & 1;
            }
            
            // Calculate the total Hamming distance at the current position
            totalHammingDist += countSetBits * (n - countSetBits);
        }
        
        return totalHammingDist;
    }
};
