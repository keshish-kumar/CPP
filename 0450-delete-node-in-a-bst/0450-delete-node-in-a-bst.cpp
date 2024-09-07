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
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        
        TreeNode* value = root; 
        TreeNode* prev = NULL;
        while(value!=NULL && key!=value->val){
            
            prev = value;
            if(key>value->val){
                value=value->right;
            }
            else{
                value=value->left;
            }
        }
        if(value==NULL) return root;

        // Now that we have reached that node we need to either find left min or right min;
        if(value->left==NULL && value->right==NULL){
            if(prev==NULL) return NULL;
            else if(prev->left==value){
                prev->left=NULL;
            }
            else{
                prev->right=NULL;
            }
        }
        else if(value->left==NULL){
            if(prev==NULL) return value->right;
            else if(prev->left==value){
                prev->left=value->right;
            }
            else{
                prev->right=value->right;
            }
        }
        else if(value->right==NULL){
            if(prev==NULL) return value->left;
            else if(prev->left==value){
                prev->left=value->left;
            }
            else{
                prev->right=value->left;
            }
            
        }
        else{
            TreeNode* r = value->right;
            TreeNode* node = value->left;
            while(node->right!=NULL){
                node=node->right;
            }
            node->right = r;
            TreeNode* temp=value;
            if(prev==NULL){
                root=value->left;;
            }
           else if(prev->left==value){
                prev->left=value->left;
            }
            else{
                prev->right=value->left;
            }
            delete(value);
        }
        return root;
    }
};