/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return NULL;
        queue<Node*> q;
        Node* node = root;
       q.push(node);

        while(!q.empty()){
            int n = q.size();
            while(n>1){
                Node* node = q.front(); q.pop();
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
                
                node->next = q.front();
                n--;
            }
            Node* node = q.front();
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
           node->next=NULL;    
            q.pop();
        }
        return root;
    }
};