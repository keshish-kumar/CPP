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
    void solve(TreeNode* root,int& ans, int count){
        if(root->left == NULL && root->right == NULL){
            ans = max(ans,count+1);
        }
        if(root->left != NULL)
            solve(root->left,ans,count+1);

        if(root->right != NULL)
            solve(root->right,ans, count+1);

    }
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int ans =1;
        int count =0;
         solve(root,ans,count);
         return ans;
    }
};