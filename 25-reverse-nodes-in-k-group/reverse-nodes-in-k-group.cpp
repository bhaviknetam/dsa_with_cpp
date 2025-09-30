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
    void reverse(ListNode* head, ListNode* tail){
        if(head == tail) return;
        reverse(head->next, tail);
        head->next->next = head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1) return head;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;
        while(head){
            int ct = 1;
            ListNode* start = head;
            while(head->next && ct < k){
                ct++;
                head = head->next;
            }
            if(ct < k) break;
            ListNode* temp = head->next;
            reverse(start, head);
            start->next = temp;
            prev->next = head;
            prev = start;
            head = temp;
        }
        return dummy->next;
    }
};