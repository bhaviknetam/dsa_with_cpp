struct Node{
    int key, val, freq;
    Node *prev, *next;
    Node(int k, int v)
        : key(k), val(v), freq(1), prev(NULL), next(NULL){}
};

class LFUCache {
private:
    unordered_map<int, Node*> cache;
    unordered_map<int, pair<Node*, Node*>> freq;
    int capacity, minf;

    void detach(Node* node){ 
        auto &[head, tail] = freq[node->freq];
        if(node->prev) node->prev->next = node->next;
        else head = node->next;

        if(node->next) node->next->prev = node->prev;
        else tail = node->prev;

        node->next = node->prev = nullptr;
        if(!head){
            freq.erase(node->freq);
            if(minf == node->freq) minf++;
        }
    }

    void attach(Node* node){
        auto &[head, tail] = freq[node->freq];
        if(!tail){
            head = tail = node;
        }else{
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    void moveToNext(Node* node){
        detach(node);
        node->freq += 1;
        attach(node);
    }

public:
    LFUCache(int capacity) : capacity(capacity), minf(1) {}
    
    int get(int key) {
        auto it = cache.find(key);
        if(it == cache.end()) return -1;
        auto node = cache[key];
        moveToNext(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(capacity <= 0) return ;
        auto it = cache.find(key);
        if(it != cache.end()){
            auto node = it->second;
            node->val = value;
            moveToNext(node);
            return;
        }
        if(cache.size() == capacity){
            auto node = freq[minf].first;
            detach(node);
            cache.erase(node->key);
            delete node;
        }
        Node* node = new Node(key, value);
        cache[key] = node;
        minf = 1;
        attach(node);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */