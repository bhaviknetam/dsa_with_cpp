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
    ListNode* middleNode(ListNode* head) {
        ListNode* curr = head;
        int length = 1;
        while(curr->next != nullptr){
            curr = curr->next;
            length++;
        }
        cout<<length<<'\n';
        curr = head;
        length /= 2;
        while(length--){
            curr = curr->next;
        }
        return curr;
    }
};