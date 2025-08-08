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
public:
    void reverseEach(ListNode* node, ListNode* prev, ListNode* tail){
        if(node == tail) return;
        reverseEach(node->next, node, tail);
        node->next = prev;
    }
    void reverse(ListNode* head, ListNode* tail){
        reverseEach(head, tail, tail);
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* nxt = head;
        ListNode* curr = dummy;
        int ct = 0;
        while(nxt){
            ct++;
            // cout << ct << '/';
            if(ct == k){
                ct = 0;
                curr->next = nxt;
                nxt = nxt->next;
                reverse(head, nxt);
                curr = head;
                head = nxt;
                continue;
            }
            nxt = nxt->next;
        }
        return dummy->next;
    }
};