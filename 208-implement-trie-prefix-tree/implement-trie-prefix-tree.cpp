struct Node {
    Node* links[26] = {nullptr};
    bool flag = false;

    void setNode(char c) {
        if (links[c - 'a'] == nullptr) {
            links[c - 'a'] = new Node();
        }
    }

    Node* nextNode(char c) {
        return links[c - 'a'];
    }

    bool isExist(char c) {
        return links[c - 'a'] != nullptr;
    }

    void setEnd() {
        flag = true;
    }

    bool isSet() {
        return flag;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }
    
    void insert(const string& word) {
        Node* node = root;
        for (char c : word) {
            if (!node->isExist(c)) {
                node->setNode(c);
            }
            node = node->nextNode(c);
        }
        node->setEnd();
    }
    
    bool search(const string& word) {
        Node* node = root;
        for (char c : word) {
            if (!node->isExist(c)) {
                return false;
            }
            node = node->nextNode(c);
        }
        return node->isSet();
    }
    
    bool startsWith(const string& prefix) {
        Node* node = root;
        for (char c : prefix) {
            if (!node->isExist(c)) {
                return false;
            }
            node = node->nextNode(c);
        }
        return true;
    }
};
