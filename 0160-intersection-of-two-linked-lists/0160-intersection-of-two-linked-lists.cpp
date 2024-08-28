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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // unordered_set<ListNode*> st;
        // ListNode* temp=headA;
        // while(temp!=NULL){
        //     st.insert(temp);
        //     temp=temp->next;
        // }

        // ListNode* temp2=headB;
        // while(temp2!=NULL){
        //     if(st.find(temp2)!=st.end()){
        //             break;
        //     }
        //     temp2=temp2->next;
        // }

        // return temp2;

        int count1=0;
        int count2=0;
        ListNode* temp1=headA;
        while(temp1!=NULL){
            count1++;
            temp1=temp1->next;
        }

        ListNode* temp2=headB;
        while(temp2!=NULL){
            count2++;
            temp2=temp2->next;
        }
        temp1=headA;
        temp2=headB;
        if(count1>count2){
            while(count1>count2){
                count1--;
                temp1=temp1->next;
            }
        }
        else if(count1<count2){
            while(count1<count2){
                count2--;
                temp2=temp2->next;
            }
        }

        while(temp1!=NULL && temp2!=NULL){
            if(temp1==temp2) return temp1;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return NULL;
    }
};