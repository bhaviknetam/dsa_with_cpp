class LRUCache {
private:unordered_map<int, list<pair<int, int>>::iterator> cache;
        list<pair<int, int>> li;
        int size;
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()) return -1;
        li.splice(li.begin(), li, cache[key]);
        return cache[key]->second;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            li.splice(li.begin(), li, cache[key]);
            cache[key]->second = value;
            return;
        }
        if(cache.size() == size){
            cache.erase(li.back().first);
            li.pop_back();
        }
        li.push_front({key, value});
        cache[key] = li.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */