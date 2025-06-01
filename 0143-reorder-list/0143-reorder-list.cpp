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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode* slow=head;
        ListNode* fast=head;
        stack<ListNode*> st;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        // fast = slow;
        // slow = slow->next;
        // fast->next = NULL;
        //prev->next=NULL;
        ListNode* mid = slow;
        slow = slow->next;
        mid->next = nullptr; 

        while(slow != NULL){
            st.push(slow);
            slow=slow->next;
        }

        // Now that we have adress with ourselfs we can procced further.
        ListNode* temp = head;
        ListNode* next = NULL;
        while(!st.empty()){
            next = temp->next;
            ListNode* t = st.top();
            temp->next = t;
            t->next=next;
            temp = next;
            st.pop();
        }

    }
};