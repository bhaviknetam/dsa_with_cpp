struct Node{
    int key, val;
    Node *prev, *next;
    Node(int k, int v):key(k), val(v), prev(NULL), next(NULL){}
};

class LRUCache {
private:
    unordered_map<int, Node*> cache;
    Node *head, *tail;
    int capacity;

    void detach(Node* node){
        if(node->prev) node->prev->next = node->next;
        else head = head->next;
        
        if(node->next) node->next->prev = node->prev;
        else tail = tail->prev;
        node->prev = node->next = nullptr;
    }

    void attach(Node* node){
        if(!tail){
            head = tail = node;
        }else{
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    void moveToLast(Node* node){
        detach(node);
        attach(node);
    }

public:
    LRUCache(int capacity):capacity(capacity),head(NULL),tail(NULL) {}
    
    int get(int key) {
        auto it = cache.find(key);
        if(it == cache.end()) return -1;
        auto node = it->second;
        moveToLast(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(capacity <= 0) return;
        auto it = cache.find(key);
        if(it != cache.end()){
            auto node = it->second;
            node->val = value;
            moveToLast(node);
            return;
        }
        if(cache.size() == capacity){
            auto node = head;
            detach(node); // add a line for node
            cache.erase(node->key);
            delete node;
        }
        Node* node = new Node(key, value);
        cache[key] = node;
        attach(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */