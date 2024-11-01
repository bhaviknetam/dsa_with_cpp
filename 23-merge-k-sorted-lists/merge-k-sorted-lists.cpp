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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp = [](ListNode* l1, ListNode* l2){
            return l1->val > l2->val;
        };
        priority_queue<ListNode*,vector<ListNode*>,decltype(comp)> pq(comp);
        for(auto& list : lists){
            if(list) pq.push(list);
        }
        ListNode* head = new ListNode();
        ListNode* curr = head;
        while(!pq.empty()){
            auto list = pq.top();
            pq.pop();
            curr->next = list;
            list = list->next;
            if(list) pq.push(list);
            curr = curr->next;
        }
        return head->next;
    }
};