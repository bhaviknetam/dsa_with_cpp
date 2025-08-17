/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* curr = head;
        while (l1 and l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        while (l1) {
            curr->next = l1;
            l1 = l1->next;
            curr = curr->next;
        }
        while (l2) {
            curr->next = l2;
            l2 = l2->next;
            curr = curr->next;
        }
        curr = head->next;
        delete head;
        return curr;
    }

    struct Comp{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n < 1) return NULL;
        if(n == 1) return lists[0];
        priority_queue<ListNode*, vector<ListNode*>, Comp> pq;
        for(int i = 0; i < n; i++){
            if(lists[i])
                pq.push(lists[i]);
        }
        ListNode dummy(0);
        ListNode* curr = &dummy;
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            curr->next = node;
            if(node->next)
                pq.push(node->next);
            curr = curr->next;
        }
        return dummy.next;
    }
};