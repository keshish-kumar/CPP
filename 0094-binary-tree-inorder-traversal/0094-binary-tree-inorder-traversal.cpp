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
    void solve(TreeNode* root, vector<int>& ans){
        if(root==NULL) return;
        solve(root->left,ans);
        ans.push_back(root->val);
        solve(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
         vector<int > ans;
        // solve(root,ans);
        // return ans;

        // we will do by morris tarversal
        TreeNode* curr = root;
        while(curr){
            if(curr->left == NULL){
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* leftnode = curr->left;
                while(leftnode->right != NULL){
                    leftnode=leftnode->right;
                }

                // Now we have attach leftmost node to curr;
                leftnode->right=curr;

                TreeNode* temp = curr;
                curr=curr->left;
                temp->left=nullptr;
            }
        }
        return ans;
    }
};