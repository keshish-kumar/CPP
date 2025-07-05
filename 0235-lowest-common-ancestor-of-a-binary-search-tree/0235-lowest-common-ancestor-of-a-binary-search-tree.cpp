/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root==p || root==q) return root;
        TreeNode* lp = lowestCommonAncestor(root->left,p,q);
        TreeNode* lq = lowestCommonAncestor(root->right,p,q);

        if((lp==p && lq==q) || (lp==q && lq==p)) return root;
        if(lp!=NULL) return lp;
        if(lq!=NULL) return lq;
        return NULL;
    }
};