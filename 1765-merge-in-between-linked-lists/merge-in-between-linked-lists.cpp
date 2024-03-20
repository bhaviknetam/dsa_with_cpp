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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    ListNode* temp1 = list1;
    ListNode* temp2 = list2;
    ListNode* node1 = nullptr;
    ListNode* node2 = nullptr;
    int count = 0;

    while (temp1->next != nullptr) {
        if (count == a - 1) 
            node1 = temp1;
        if (count == b) 
            node2 = temp1->next;
        temp1 = temp1->next;
        count++;
    }

    while (temp2->next != nullptr) {
        temp2 = temp2->next;
    }

    temp1 = list1;
    while (temp1 != nullptr) {
        if (temp1 == node1) {
            temp1->next = list2;
        }
        if (temp1 == temp2) {
            temp2->next = node2;
        }
        temp1 = temp1->next;
    }
    return list1;
}

};