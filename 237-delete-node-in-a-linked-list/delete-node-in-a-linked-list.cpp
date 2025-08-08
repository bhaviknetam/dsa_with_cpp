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
    void deleteNode(ListNode* node) {
        if(!node->next){
            delete node;
            return;
        }
        ListNode* nxt = node->next;
        while(nxt->next){
            swap(node->val, nxt->val);
            node = nxt;
            nxt = nxt->next;
        }
        swap(node->val, nxt->val);
        delete nxt;
        node->next = nullptr;
    }
};