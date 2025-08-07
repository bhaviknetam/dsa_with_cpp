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
        while(curr->next != nullptr){
            curr = curr->next;
        }
        reverse(head, nullptr);
        return curr;
    }
};