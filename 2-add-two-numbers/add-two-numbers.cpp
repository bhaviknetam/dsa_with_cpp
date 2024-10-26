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
    ListNode* addTwoNumbers(ListNode* list1, ListNode* list2) {
        ListNode* list3 = new ListNode();
        ListNode* temp = list3;
        int carry = 0;
        while(list1 and list2){
            ListNode* node = new ListNode();
            temp->next = node;
            temp = node;
            int sum = list1->val+list2->val+carry;
            if(sum >= 10) {
                carry = sum / 10;
                sum = sum % 10;
            }else carry = 0;
            temp->val = sum;
            list1 = list1->next;
            list2 = list2->next;
        }
        while(list1){
            ListNode* node = new ListNode();
            temp->next = node;
            temp = node;
            int sum = list1->val+carry;
            if(sum >= 10) {
                carry = sum / 10;
                sum = sum % 10;
            }else carry = 0;
            temp->val = sum;
            list1 = list1->next;
        }
        while(list2){
            ListNode* node = new ListNode();
            temp->next = node;
            temp = node;
            int sum = list2->val+carry;
            if(sum >= 10) {
                carry = sum / 10;
                sum = sum % 10;
            }else carry = 0;
            temp->val = sum;
            list2 = list2->next;
        }
        if(carry){
            ListNode* node = new ListNode(carry);
            temp->next = node;
        }
        return list3->next;
    }
};