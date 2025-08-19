struct Node {
    int index; // store index of array element
    Node* prev;
    Node* next;
    Node(int i) : index(i), prev(NULL), next(NULL) {}
};

// Doubly Linked List class for our custom deque
class DLL {
    Node* head;
    Node* tail;

public:
    DLL() : head(NULL), tail(NULL) {}

    bool empty() { return head == NULL; }

    int front() { return head->index; }

    int back() { return tail->index; }

    void pop_front() {
        if (head) {
            Node* temp = head;
            head = head->next;
            if (head)
                head->prev = NULL;
            else
                tail = NULL;
            delete temp;
        }
    }

    void pop_back() {
        if (tail) {
            Node* temp = tail;
            tail = tail->prev;
            if (tail)
                tail->next = NULL;
            else
                head = NULL;
            delete temp;
        }
    }

    void push_back(int i) {
        Node* node = new Node(i);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> result;
        DLL dq;

        for (int i = 0; i < n; i++) {
            // Remove indices out of this window
            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // Remove smaller elements (they can't be max)
            while (!dq.empty() && arr[dq.back()] <= arr[i])
                dq.pop_back();

            dq.push_back(i);

            // Record answer when we have a full window
            if (i >= k - 1)
                result.push_back(arr[dq.front()]);
        }
        return result;
    }
};