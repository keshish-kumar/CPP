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
    ListNode* reverse(ListNode* head){
        ListNode* temp=head;
        ListNode* prev=NULL;
        ListNode* next = NULL;
        while(temp!=NULL){
            next = temp->next;
            temp->next= prev;
            prev=temp;
            temp=next;
        }

        return prev;

    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL) return NULL;

        int count=0;
        
        ListNode* node = new ListNode(-1);
        ListNode* o = node;

        node->next=head;
        head=o;
        ListNode* temp = head->next;
        ListNode* s2nd = head->next;
       
        while(temp!=NULL){
            count++;
            ListNode* t = temp->next;
            if(count==k){
                temp->next=NULL;
                ListNode* headt = reverse(s2nd);
                head->next = headt;
                head = s2nd;
                s2nd=t;
                count=0;
            }
            temp=t;
        }
        if(count!=0){
            head->next=s2nd;
        }
        return o->next;
    }
};