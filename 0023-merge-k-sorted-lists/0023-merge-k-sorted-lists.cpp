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
        // we can use noromal vector but it will solved in n*logn
        // we will use priority_queue
        ListNode* l = new ListNode(0);
        ListNode* temp = l;
        priority_queue<pair<int,ListNode*> , vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
        // first we need to keep 
        for(auto list:lists){
            if(list)
             pq.push({list->val,list});
        }

        while(!pq.empty()){
            int element = pq.top().first;
            ListNode* t = pq.top().second;
            temp->next = new ListNode(element);
            temp = temp->next;
            pq.pop();
             if(t->next){
                pq.push({t->next->val,t->next});
             }
        }

        return l->next;
    }
};