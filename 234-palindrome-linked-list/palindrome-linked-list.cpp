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
    void reverse(ListNode* node, ListNode* prev){
        if(node == nullptr) return;
        reverse(node->next, node);
        node->next = prev;
    }
    bool isPalindrome(ListNode* head) {
        int len = 1;
        ListNode* curr = head;
        while(curr->next){
            len++;
            curr = curr->next;
        }
        ListNode* mid = head;
        for(int i = 0; i < len / 2; i++){
            mid = mid->next;
        }
        reverse(mid->next, mid);
        mid->next = nullptr;
        while(head && curr){
            if(curr->val != head->val) return false;
            curr = curr->next;
            head = head->next;
        }
        return true;
    }
};