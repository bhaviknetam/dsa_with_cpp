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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* list3 = new ListNode();
        ListNode* temp = list3;
        while(list1 and list2){
            ListNode* node = new ListNode();
            temp->next = node;
            temp = node;
            if(list1->val < list2->val){
                temp->val = list1->val;
                list1 = list1->next;
            }else{
                temp->val = list2->val;
                list2 = list2->next;
            }
        }
        while(list1){
            ListNode* node = new ListNode();
            temp->next = node;
            temp = node;
            temp->val = list1->val;
            list1 = list1->next;
        }
        while(list2){
            ListNode* node = new ListNode();
            temp->next = node;
            temp = node;
            temp->val = list2->val;
            list2 = list2->next;
        }
        return list3->next;
    }
};