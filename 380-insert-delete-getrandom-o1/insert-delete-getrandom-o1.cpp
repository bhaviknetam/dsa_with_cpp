class RandomizedSet {
public:
    vector<int> v;
    unordered_map<int,int> m;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m.count(val))return false;
        int n = v.size();
        v.push_back(val);
        m.insert({val, n});
        return true;
    }
    
    bool remove(int val) {
        if(!m.count(val))return false;
        int idx = m[val];
        int n = v.size();
        m[v[n-1]]=idx;
        swap(v[idx], v[n-1]);
        v.pop_back();
        m.erase(val);
        return true;
    }
    
    int getRandom() {
        int n = v.size();
        int random = rand() % n;
        return v[random];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */