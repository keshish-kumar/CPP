/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        stack<TreeNode* > st;
        //st.push(NULL);
        TreeNode* temp = root;

        while(temp!=NULL){
            st.push(temp->right);

            TreeNode* node = temp;

            node->right=NULL;
            temp=node->left;
            if(node->left!=NULL)
             node->right = node->left;
            node->left=NULL;

            if(temp==NULL){
                while(!st.empty() && st.top()==NULL) st.pop();
                if(st.empty()) break;
                temp=st.top();
                st.pop();
                node->right=temp;
            }
            
        }   
    }
};