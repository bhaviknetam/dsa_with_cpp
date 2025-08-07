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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* last = dummy;
        while(n--){
            last = last->next;
        }
        head = dummy;
        while(last->next){
            last = last->next;
            head = head->next;
        }
        last = head->next;
        head->next = last->next;
        delete last;
        return dummy->next;
    }
};