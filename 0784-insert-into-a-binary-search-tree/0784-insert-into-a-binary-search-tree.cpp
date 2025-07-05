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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* temp = root;
        TreeNode* node = new TreeNode(val);
        if(temp==NULL) return node;
        while(temp){
            if(val >temp->val ){
                if(temp->right == NULL){
                    temp->right=node;
                    break;
                }
                temp=temp->right;
            }
            else{
                if(temp->left == NULL){
                    temp->left = node;
                    break;
                }
                temp=temp->left;
            }
        }
        return root;
    }
};