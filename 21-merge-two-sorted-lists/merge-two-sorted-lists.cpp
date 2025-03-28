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
            if(list1->val < list2->val){
                temp->next = list1;
                list1 = list1->next;
            }else{
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        while(list1){
            temp->next = list1;
            list1 = list1->next;
            temp = temp->next;
        }
        while(list2){
            temp->next = list2;
            list2 = list2->next;
            temp = temp->next;
        }
        return list3->next;
    }
};