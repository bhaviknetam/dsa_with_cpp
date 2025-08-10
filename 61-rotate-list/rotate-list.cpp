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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int len = 1;
        ListNode* curr = head;
        while(curr->next){
            len++;
            curr = curr->next;
        }
        k = k % len;
        if(!k) return head;
        int d = len - k;
        curr->next = head;
        while(d--){
            curr = curr->next;
        }
        head = curr->next;
        curr->next = NULL;
        return head;
    }
};