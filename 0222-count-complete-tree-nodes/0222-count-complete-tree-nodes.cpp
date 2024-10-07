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
    int countNodes(TreeNode* root) {
        // we know if the tree is complete than 2^h-1 is the formulae
        
        int lh = left(root);
        int rh = right(root);
        
        if(rh == lh) return (1<<rh)-1 ;
        
        return 1+countNodes(root->left)+countNodes(root->right);
    }
    
    int left(TreeNode* root){
        if(root == NULL) return 0;
        int count =0;
        while(root!=NULL){
            root = root->left;
            count++;
        }
        return count;
    }
    int right(TreeNode* root){
        if(root==NULL) return 0;
        int count =0;
        while(root!=NULL){
            root = root->right;
            count++;
        }
        return count;
    }
};