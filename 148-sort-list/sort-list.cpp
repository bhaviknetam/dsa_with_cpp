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
    ListNode* findSecond(ListNode* head){
        if(!head) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while(true){
            fast = fast->next;
            if(fast == nullptr) return slow;
            fast = fast->next;
            if(fast == nullptr) return slow;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* first, ListNode* second){
        ListNode* dummy = new ListNode();
        ListNode* prev = dummy;
        while(first && second){
            if(first->val <= second->val){
                prev->next = first;
                first = first->next;
            }else{
                prev->next = second;
                second = second->next;
            }
            prev = prev->next;
        }
        while(first){
            prev->next = first;
            first = first->next;
            prev = prev->next;
        }
        while(second){
            prev->next = second;
            second = second->next;
            prev = prev->next;
        }
        return dummy->next;
    }

    ListNode* mergeSort(ListNode* first){
        if(!first || first->next == nullptr) return first;
        ListNode* last = findSecond(first);
        ListNode* second = last->next;
        last->next = nullptr;
        return merge(mergeSort(first), mergeSort(second));
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        return mergeSort(head);
    }
};