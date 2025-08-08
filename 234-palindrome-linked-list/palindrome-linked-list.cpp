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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
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
        curr = reverse(mid);
        mid->next = nullptr;
        while(head && curr){
            if(curr->val != head->val) return false;
            curr = curr->next;
            head = head->next;
        }
        return true;
    }
};