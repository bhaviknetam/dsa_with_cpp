class MedianFinder {
private: 
    vector<int> nums;
    void insertionSort(){
        int n = nums.size();
        int i = 0;
        while(i < n){
            if(nums[i] > nums[n - 1]){
                swap(nums[i], nums[n-1]);
            }
            i++;
        }
    }

public:
    MedianFinder() {}
    
    void addNum(int num) {
        auto it = lower_bound(nums.begin(), nums.end(), num);
        nums.insert(it, num);
    }
    
    double findMedian() {
        int n = nums.size();
        // for(int i : nums) cout << i << ';';
        cout<< endl;
        if(n & 1) return (double)nums[n / 2];
        return (nums[n / 2] + nums[n / 2 - 1])/ 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */