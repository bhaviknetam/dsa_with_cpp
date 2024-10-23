class RandomizedSet {
private: unordered_set<int> s;
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(!s.count(val)) {
            s.insert(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(s.count(val)) {
            s.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int n = s.size();
        int val = rand() % n;
        auto it = next(s.begin(), val);
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */