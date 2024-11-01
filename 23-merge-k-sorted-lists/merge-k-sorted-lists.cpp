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
        vector<int> store;
        for(auto& list : lists){
            while(list != NULL){
                store.push_back(list->val);
                list = list->next;
            }
        }
        sort(store.begin(), store.end());
        ListNode* ans = new ListNode();
        ListNode* curr = ans;
        for(int& num : store){
            curr->next=new ListNode(num);
            curr=curr->next;
        }
        return ans->next;
    }
};