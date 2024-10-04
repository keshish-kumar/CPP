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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return NULL;
        //if(k==0) return head;

        // first we have to count total length of linked list
        int ll=0;
        ListNode* temp=head;
        while(temp!=NULL){
            ll++;
            temp=temp->next;
        }

        // ll is the lenth of list after ll-n we have to rotate list
        k = k%ll;
        if(k==0) return head;
        
        ll = ll-k;
        ListNode* headnew = NULL;
        temp=head;
        while(ll>1){
            temp=temp->next;
            ll--;
        }
        headnew=temp->next;
        temp->next=NULL;
        temp=headnew;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=head;
        head=headnew;
        return head;
    }
};