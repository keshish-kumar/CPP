/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // first method is to store in the set.
        // unordered_set<ListNode*> st;
        // ListNode* temp=head;
        // while(temp != NULL){
        //     if(st.find(temp) != st.end()) return true;
        //     st.insert(temp);
        //     temp = temp->next;
        // }
        // return false;

        // nOw heir and tortoise method
        if(head == NULL) return false;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL){
            slow = slow->next;
            fast =fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }
};