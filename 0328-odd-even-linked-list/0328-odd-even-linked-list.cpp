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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL) return head;
        ListNode* head1=head;
        ListNode* head2=head->next;
        ListNode* t1 = head1;
        ListNode* t2 = head2;
        while(t1->next!=NULL && t2->next!=NULL){
            ListNode* temp = t1->next->next;
            t1->next=temp;
            t1=temp;

            temp = t2->next->next;
            t2->next=temp;
            t2=temp;
        }

        t1->next=head2;
        return head1;

    }
};