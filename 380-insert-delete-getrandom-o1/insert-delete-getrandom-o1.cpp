class RandomizedSet {
public:
    unordered_set<int> v;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        auto it = v.find(val);
        if(it != v.end()){
            return false;
        }
        v.insert(val);
        return true;
    }
    
    bool remove(int val) {
        auto it = v.find(val);
        if(it != v.end()){
            v.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int r = rand() % v.size();
        auto it = next(v.begin(), r);
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