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
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* curr = head;
        while (l1 and l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        while (l1) {
            curr->next = l1;
            l1 = l1->next;
            curr = curr->next;
        }
        while (l2) {
            curr->next = l2;
            l2 = l2->next;
            curr = curr->next;
        }
        curr = head->next;
        delete head;
        return curr;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n < 1) return NULL;
        int adder = 1;
        while (adder < n) {
            for (int i = 0; i + adder < n; i += (adder << 1)) {
                lists[i] = mergeTwoLists(lists[i], lists[i + adder]);
            }
            adder <<= 1;
        }

        return lists[0];
    }
};