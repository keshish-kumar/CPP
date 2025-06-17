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
    TreeNode* invertTree(TreeNode* root) {
        // if(root == NULL) return NULL;
        // queue<TreeNode* > q;
        // q.push(root);
        // while(!q.empty()){
        //     TreeNode* curr = q.front();

        //     TreeNode* temp = curr->right;
        //     curr->right = curr->left;
        //     curr->left = temp;
        //     q.pop();
        //     if(curr->left != NULL)
        //     q.push(curr->left);
        //     if(curr->right!= NULL)
        //     q.push(curr->right);
        // }

        // return root;

        if(root == NULL) return NULL;
        if(root->left == NULL && root->right == NULL) return root;
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        root->left = right;
        root->right = left;

        return root;
    }
};