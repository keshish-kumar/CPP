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
            ListNode* temp1=l1;
            ListNode* temp2=l2;
            int carry=0;
            ListNode* prev1=NULL;
            ListNode* prev2=NULL;
            while(temp1!=NULL && temp2!=NULL){
                int n1 = temp1->val;
                int n2 = temp2->val;
                if((temp1->val+temp2->val+carry)>9){
                    
                    temp1->val= (n1+carry+n2)%10;
                    temp2->val=(n1+n2+carry)%10;
                    carry=1;
                }
                else{
                    
                    temp1->val = n1+n2+carry;
                    temp2->val = n1+n2+carry;
                    carry=0;
                }
                prev1=temp1;
                temp1=temp1->next;
                prev2=temp2;
                temp2=temp2->next;

            }
            bool flag1=false;
           
            while(temp1!= NULL){
                if((temp1->val+carry) >9){
                    temp1->val= (temp1->val+carry)%10;
                    carry=1;
                }
                else{
                    temp1->val+=carry;
                    carry=0;
                }
                flag1=true;
                prev1=temp1;
                temp1=temp1->next;
            }

            bool flag2=false;
            
            while(temp2!= NULL){
                if((temp2->val+carry) >9){
                    temp2->val= (temp2->val+carry)%10;
                    carry=1;
                }
                else{
                    temp2->val+=carry;
                    carry=0;
                }
                flag2=true;
                prev2=temp2;
                temp2=temp2->next;
            }

            if(carry==1 && flag1){
                ListNode* node=new ListNode(carry);
                prev1->next=node;
            }
            if(carry==1 && flag2){
                ListNode* node=new ListNode(carry);
                prev2->next=node;
            }
            if(carry==1){
                ListNode* node=new ListNode(carry);
                prev1->next=node;
            }


            if(flag1==true){
                return l1;
            }
            else if(flag2==true){
                return l2;
            }
            else{ 
                return l1;
            }


    }
};