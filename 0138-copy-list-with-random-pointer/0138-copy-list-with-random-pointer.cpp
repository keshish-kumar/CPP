/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        Node* temp = head;
        
        Node* node = new Node(temp->val);
        Node* headtemp= node;
       
        map<Node*,int> mp; // this will store the adress and index of original list
        map<int,Node*> copy; // this will store the index and its adress of copied list
        mp[temp] = 0;
        temp=temp->next;
        copy[0] = node;
        int index =1;
        while(temp!=NULL){
            mp[temp] = index; 
            Node* d = new Node(temp->val);
            copy[index] = d;
            index++;
            d->next=NULL;
            node->next = d;
            node=node->next;
            temp=temp->next;
        }
        // Now we have to handle for the case of random pointer

        map<int,int> m;
        temp=head;
        index=0;
        while(temp!=NULL){
            if(temp->random == NULL){
                m[index] = -1;
            }
            else{
                m[index] = mp[temp->random];
            }
            index++;
            temp=temp->next;
        } 

        temp= headtemp;
        index= 0;
        while(temp!=NULL){
            int t = m[index];
            if(t==-1){
                temp->random=NULL;
            }
            else
                temp->random = copy[t];
            index++;
            temp=temp->next;
        }

        return headtemp;
    }
};