class RandomizedCollection {
public:
    unordered_map<int, int> m;
    vector<int> v;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        auto it = m.find(val);
        v.push_back(val);
        if(it != m.end()){
            m[val]++;
            return false;
        }
        m[val]++;
        return true;

    }
    
    bool remove(int val) {
        auto it = m.find(val);
        if(it != m.end()){
            auto it1 = find(v.begin(), v.end(), val);
            v.erase(it1);
            m[val]--;
            if(m[val]==0) m.erase(val);
            return true;
        }
        return false; 
    }
    
    int getRandom() {
        int r = rand() % v.size();
        return v[r];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */