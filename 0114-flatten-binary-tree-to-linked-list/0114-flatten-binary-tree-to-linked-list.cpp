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
    void solve(TreeNode* root,stack<TreeNode*> & st){
        if(root==NULL && st.empty()) return ;
         TreeNode* temp=root;
        st.push(temp->right);
       
        if(temp->left!=NULL){
            temp->right=temp->left;
            temp->left = NULL;
            solve(root->right,st);
        }
        else{
            while(!st.empty() && st.top()==NULL ) st.pop();
            if(st.empty()) return ;
            temp->right=st.top();st.pop();
            solve(temp->right,st);

        }

    }
    void flatten(TreeNode* root) {
        stack<TreeNode*> st;
        solve(root,st);
    }
};