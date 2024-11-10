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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            length++;
            temp=temp->next;
        }
        n = length-n;
        if(n==0) return head->next;
        temp=head;
        ListNode* prev = NULL;
        while(n--){
            prev =  temp;
            temp=temp->next;
        }
        
        if(temp!=NULL)
            prev->next=temp->next;
        else
            prev->next=NULL;
        
        return head;
    }
};