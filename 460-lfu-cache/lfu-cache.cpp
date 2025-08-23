#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key, val, freq;
    Node *prev, *next;
    Node(int k, int v)
      : key(k), val(v), freq(1), prev(nullptr), next(nullptr)
    {}
};

class LFUCache {
private:
    int capacity, currSize, minf;
    // key → Node*
    unordered_map<int, Node*> cache;
    // freq → {head, tail} of a doubly-linked list of Nodes with that freq
    unordered_map<int, pair<Node*,Node*>> freqList;

    // Remove node from its current freq‐list, updating head/tail,
    // erasing the list if it becomes empty, and bumping minf if needed.
    void detach(Node* node) {
        int f = node->freq;
        auto &bucket = freqList[f];
        Node* &head = bucket.first;
        Node* &tail = bucket.second;

        // unlink
        if (node->prev) node->prev->next = node->next;
        else            head = node->next;

        if (node->next) node->next->prev = node->prev;
        else            tail = node->prev;

        node->prev = node->next = nullptr;

        // if that freq‐list is now empty, remove it
        if (!head) {
            freqList.erase(f);
            if (minf == f) 
                minf++;
        }
    }

    // Append node to the tail of its freq‐list (new or existing)
    void attach(Node* node) {
        int f = node->freq;
        auto &bucket = freqList[f];
        Node* &head = bucket.first;
        Node* &tail = bucket.second;

        if (!tail) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

public:
    LFUCache(int capacity)
      : capacity(capacity), currSize(0), minf(0)
    {}

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end())
            return -1;

        Node* node = it->second;
        detach(node);

        node->freq++;
        attach(node);

        return node->val;
    }

    void put(int key, int value) {
        if (capacity <= 0) 
            return;

        // update existing
        auto it = cache.find(key);
        if (it != cache.end()) {
            Node* node = it->second;
            node->val = value;
            // bump frequency via get
            get(key);
            return;
        }

        // evict if full
        if (currSize == capacity) {
            // least‐freq = minf, LRU in that bucket = head
            Node* nodeEvict = freqList[minf].first;
            detach(nodeEvict);
            cache.erase(nodeEvict->key);
            delete nodeEvict;
            currSize--;
        }

        // insert new with freq=1
        Node* node = new Node(key, value);
        cache[key] = node;
        minf = 1;
        currSize++;
        attach(node);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
