/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution {
  public:
    int kthLargest(Node *root, int k) {
        // Your code here
        int count =0;
        stack<Node*> st;
        Node* curr = root;
        while(!st.empty() || curr){
            
            while(curr){
                st.push(curr);
                curr=curr->right;
            }
            
            count++;
            curr = st.top();
            st.pop();
            if(count==k) return curr->data; 
            
            curr = curr->left;
            
            
        }
        return -1;
    }
};