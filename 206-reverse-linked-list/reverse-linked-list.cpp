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
    void reverse(ListNode* head, ListNode* prev){
        if(head == nullptr) return;
        reverse(head->next, head);
        head->next = prev;
    }

    ListNode* reverseList(ListNode* head) {
        if(!head or !head->next) return head;
        ListNode* curr = head;
        ListNode* nxt = head->next;
        while(nxt != nullptr){
            ListNode* temp = nxt->next;
            nxt->next = curr;
            curr = nxt;
            nxt = temp;
        }
        head->next = nullptr;
        return curr;
    }
};