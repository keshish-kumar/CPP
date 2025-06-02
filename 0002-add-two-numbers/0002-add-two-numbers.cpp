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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* t1=l1;
        ListNode* t2=l2;
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;
        int carry = 0;
        while(t1!=NULL && t2!=NULL){
            int n1 = t1->val;
            int n2 = t2->val;
            int n = n1+n2+carry;
            if(n>9){
                carry = 1;
                n = n-10; // get the digit at ones place
            }
            else{
                carry = 0;
            }
            ListNode* node = new ListNode(n);
            head->next = node;
            head = node;
            t1=t1->next;
            t2=t2->next;
        }
        while(t1!=NULL){
            int n = t1->val+carry;
            if(n>9){
                carry = 1;
                n = n-10; // get the digit at ones place
            }
            else{
                carry = 0;
            }
            ListNode* node = new ListNode(n);
            t1 = t1->next;
            head->next = node;
            head = node;
        }
        while(t2!=NULL){
            int n = t2->val+carry;
            if(n>9){
                carry = 1;
                n = n-10; // get the digit at ones place
            }
            else{
                carry = 0;
            }
            ListNode* node = new ListNode(n);
            t2=t2->next;
            head->next = node;
            head = node;
        }
        if(carry==1){
            ListNode* node = new ListNode(1);
            head->next = node;
            head = node;
        }
        return dummy->next;

    }
};