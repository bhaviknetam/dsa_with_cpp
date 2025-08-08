/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;
        ListNode* hare = head;
        ListNode* tortoise = head;
        while(true){
            if(!hare) return false;
            hare = hare->next;
            if(!hare) return false;
            hare = hare->next;
            tortoise = tortoise->next;
            if(hare == tortoise) return true;
        }
        return false;
    }
};