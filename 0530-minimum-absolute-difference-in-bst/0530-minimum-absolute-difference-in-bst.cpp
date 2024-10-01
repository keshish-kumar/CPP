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
    void inorder(TreeNode* root, TreeNode*& prev,int & ans){
        if(root==NULL) return;
        
        // left
        inorder(root->left,prev,ans);
        if(prev!=NULL){
            ans = min(ans,abs(root->val-prev->val));
        }
        prev=root;
        inorder(root->right,prev,ans);
    }
    int getMinimumDifference(TreeNode* root) {
        // we need to keep track of maximum form left and minimum from right than find the difference from that node
        int ans = 1e9;
        TreeNode* prev  = NULL;
        inorder(root,prev,ans);
        return ans;

        
    }
};