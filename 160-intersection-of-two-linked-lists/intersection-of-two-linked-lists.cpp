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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0, len2 = 0;
        ListNode* curr = headA;
        while(curr) len1++, curr = curr->next;
        curr = headB;
        while(curr) len2++, curr = curr->next;
        for(int i = 0; i < abs(len1-len2);i++){
            (len1 > len2) ? (headA=headA->next):( headB=headB->next);
        }
        while(headA && headB){
            if(headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
};